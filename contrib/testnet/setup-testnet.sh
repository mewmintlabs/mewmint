#!/bin/bash

# Configuration
MEWMINT_HOME="$HOME/.mewmint"
TESTNET_DIR="$MEWMINT_HOME/testnet3"
CONF_FILE="$TESTNET_DIR/mewmint.conf"

# Create directories
mkdir -p "$TESTNET_DIR"

# Copy configuration
cp "$(dirname "$0")/mewmint.conf" "$CONF_FILE"

# Set permissions
chmod 600 "$CONF_FILE"

# Open required ports (requires sudo)
echo "Opening testnet ports..."
sudo ufw allow 18335/tcp comment 'Mewmint testnet P2P'
sudo ufw allow 18336/tcp comment 'Mewmint testnet RPC'

# Create data directory structure
mkdir -p "$TESTNET_DIR/blocks"
mkdir -p "$TESTNET_DIR/chainstate"
mkdir -p "$TESTNET_DIR/database"

echo "Testnet node configuration complete!"
echo "Configuration file: $CONF_FILE"
echo "Data directory: $TESTNET_DIR"
echo
echo "To start the testnet node, run:"
echo "mewmintd -conf=$CONF_FILE -datadir=$TESTNET_DIR"
