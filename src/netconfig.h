#ifndef MEWMINT_NETCONFIG_H
#define MEWMINT_NETCONFIG_H

// Magic numbers cho các mạng của Mewmint
// Được chọn để không xung đột với các cryptocurrency phổ biến
// Bitcoin:     0xf9, 0xbe, 0xb4, 0xd9
// Litecoin:    0xfb, 0xc0, 0xb6, 0xdb
// Dogecoin:    0xc0, 0xc0, 0xc0, 0xc0
// Bitcoin Cash: 0xe3, 0xe1, 0xf3, 0xe8

namespace NetConfig {
    // Network magic numbers
    // Mainnet: f4 + be (như Bitcoin) + d4 (khác) + e9 (khác)
    static const unsigned char MAINNET_MESSAGE_START[4] = {0xf4, 0xbe, 0xd4, 0xe9}; // Mewmint mainnet
    
    // Testnet: 0b (như Bitcoin testnet) + 12 (khác) + 08 (khác) + 06 (khác)
    static const unsigned char TESTNET_MESSAGE_START[4] = {0x0b, 0x12, 0x08, 0x06}; // Mewmint testnet
    
    // Signet: 0a (như Bitcoin signet) + 04 (khác) + ce (khác) + 41 (khác)
    static const unsigned char SIGNET_MESSAGE_START[4] = {0x0a, 0x04, 0xce, 0x41}; // Mewmint signet
    
    // Regtest: fa (như Bitcoin regtest) + bc (khác) + b5 (khác) + dc (khác)
    static const unsigned char REGTEST_MESSAGE_START[4] = {0xfa, 0xbc, 0xb5, 0xdc}; // Mewmint regtest

    // Default ports
    // Port ranges theo tiêu chuẩn cryptocurrency:
    // Mainnet P2P: 8330-8339
    // Mainnet RPC: 8330-8339
    // Testnet P2P: 18330-18339
    // Testnet RPC: 18330-18339
    
    // Mainnet ports (8335-8336 để tránh xung đột với Bitcoin 8333)
    static const int MAINNET_PORT = 8335;        // Mainnet P2P port
    static const int MAINNET_RPC_PORT = 8336;    // Mainnet RPC port
    
    // Testnet ports (18335-18336 để tránh xung đột với Bitcoin testnet 18333)
    static const int TESTNET_PORT = 18335;       // Testnet P2P port
    static const int TESTNET_RPC_PORT = 18336;   // Testnet RPC port
    
    // Signet ports (38335-38336 để tránh xung đột với Bitcoin signet 38333)
    static const int SIGNET_PORT = 38335;        // Signet P2P port
    static const int SIGNET_RPC_PORT = 38336;    // Signet RPC port
    
    // Regtest ports (18445-18446 để tránh xung đột với Bitcoin regtest 18444)
    static const int REGTEST_PORT = 18445;       // Regtest P2P port
    static const int REGTEST_RPC_PORT = 18446;   // Regtest RPC port

    // Seed nodes for mainnet
    static const char* const MAINNET_SEEDS[] = {
        "seed1.mewmint.org",
        "seed2.mewmint.org",
        "seed3.mewmint.org",
        "seed4.mewmint.org",
        nullptr
    };

    // Seed nodes for testnet
    static const char* const TESTNET_SEEDS[] = {
        "testnet-seed1.mewmint.org",
        "testnet-seed2.mewmint.org",
        "testnet-seed3.mewmint.org",
        nullptr
    };

    // Seed nodes for signet
    static const char* const SIGNET_SEEDS[] = {
        "signet-seed1.mewmint.org",
        "signet-seed2.mewmint.org",
        nullptr
    };
} // namespace NetConfig

#endif // MEWMINT_NETCONFIG_H
