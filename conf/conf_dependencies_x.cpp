#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <array>

int run_cmd(const std::string &cmd) {
    std::array<char, 256> buffer;
    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe) return -1;
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) std::cout << buffer.data();
    int rc = pclose(pipe);
    if (rc == -1) return -1;
#ifdef WEXITSTATUS
    return WEXITSTATUS(rc);
#else
    return rc;
#endif
}

int main() {
    std::cout << "1) Checking for Apple Command Line Tools (clang++)...\n";
    if (run_cmd("which clang++ >/dev/null 2>&1") != 0) {
        std::cout << "Installing Apple Command Line Tools (may prompt)...\n";
        // This opens the softwareupdate installation flow; it may require user interaction.
        if (run_cmd("xcode-select --install >/dev/null 2>&1 || true") != 0) {
            std::cerr << "Failed to invoke xcode-select --install (already installed or manual intervention required).\n";
        } else {
            std::cout << "Requested Command Line Tools install. Wait for completion then re-run this program if needed.\n";
        }
    } else {
        std::cout << "Apple Command Line Tools present.\n";
    }

    std::cout << "2) Checking for curl...\n";
    if (run_cmd("which curl >/dev/null 2>&1") != 0) {
        std::cerr << "curl not found. Please install curl and re-run.\n";
        return 2;
    }

    std::cout << "3) Checking for Homebrew...\n";
    if (run_cmd("which brew >/dev/null 2>&1") != 0) {
        std::cout << "Homebrew not found. Installing Homebrew (may request password)...\n";
        // Official Homebrew install script
        if (run_cmd("/bin/bash -c \"$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)\"") != 0) {
            std::cerr << "Homebrew installation failed or was cancelled.\n";
            return 3;
        }
    } else {
        std::cout << "Homebrew found.\n";
    }

    std::cout << "4) Updating Homebrew...\n";
    run_cmd("brew update || true");

    std::cout << "5) Installing Ollama via official installer script (curl | sh)...\n";
    // Use the recommended curl installer provided by Ollama
    if (run_cmd("/bin/sh -c \"curl -fsSL https://ollama.com/install.sh | sh\"") != 0) {
        std::cerr << "Ollama installer script failed.\n";
        // fallback: try brew cask
        std::cout << "Attempting Homebrew install of ollama as fallback...\n";
        if (run_cmd("brew install --cask ollama || brew install ollama") != 0) {
            std::cerr << "Failed to install ollama via Homebrew as well.\n";
            return 4;
        }
    }

    std::cout << "6) Ensure ollama CLI is available in PATH (may require new shell)...\n";
    if (run_cmd("which ollama >/dev/null 2>&1") != 0) {
        std::cout << "ollama not found in PATH. Attempting to source common install locations and retry...\n";
        // Try common locations added by installer
        run_cmd("export PATH=\"$HOME/.local/bin:$HOME/.ollama/bin:/usr/local/bin:/opt/homebrew/bin:$PATH\" && which ollama >/dev/null 2>&1");
        if (run_cmd("which ollama >/dev/null 2>&1") != 0) {
            std::cerr << "ollama still not found. You may need to open a new terminal or add ollama to PATH, then re-run.\n";
        }
    } else {
        std::cout << "ollama CLI found.\n";
    }

    std::cout << "7) Starting ollama daemon (if required)...\n";
    run_cmd("ollama start 2>&1 || true");

    std::cout << "8) Pulling qwen2.5-coder model via ollama...\n";
    if (run_cmd("ollama pull qwen2.5-coder") != 0) {
        std::cerr << "Failed to pull qwen2.5-coder. Check network, model name, or ollama authentication.\n";
        return 5;
    }

    std::cout << "Done. Verify model with: ollama list\n";
    return 0;
}
