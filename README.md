# Code Review Assistant 

A modern, high-performance Python GUI application for reviewing code using a local Large Language Model (LLM). Features hybrid Python-C++ architecture for optimal performance, complete privacy, and professional code analysis.

[![Python 3.8+](https://img.shields.io/badge/python-3.8+-blue.svg)](https://www.python.org/downloads/)
[![PyQt6](https://img.shields.io/badge/GUI-PyQt6-green.svg)](https://www.riverbankcomputing.com/software/pyqt/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

---

## Features

### Core Functionality
-  **Local LLM-powered reviews** using [Ollama](https://ollama.com/) + [Qwen2.5-Coder](https://huggingface.co/Qwen/Qwen2.5-Coder)
-  **Modern PyQt6 GUI** with native look-and-feel
-  **Smart file picker** with validation for Python files
-  **Complete privacy** - all processing stays on your machine
-  **Interactive follow-up questions** for deeper analysis

### Performance Enhancements
-  **Hybrid C++ backend** for performance-critical operations
-  **Adaptive streaming** with intelligent buffering
-  **Multi-threaded execution** (UI never freezes)
-  **Real-time progress tracking** and status updates
-  **Efficient memory management** with conversation limits

### Professional Features
-  **Dark/Light theme support** with system integration
-  **Enhanced markdown rendering** with syntax highlighting
-  **Comprehensive error handling** and retry logic
-  **Connection testing** and health monitoring
-  **File caching** for improved performance
-  **Configurable settings** via environment variables and config files

---

### 1. Prerequisites

**System Requirements:**
- Python 3.8 or higher
- CMake 3.12 or higher
- C++ compiler (GCC/Clang/MSVC)
- Ollama with Qwen2.5-Coder model

**Install Ollama & Model:**
```bash
# Install Ollama (visit https://ollama.com for platform-specific instructions)

# Pull the code review model
ollama pull qwen2.5-coder

# Start the model (keep running in background)
ollama run qwen2.5-coder
```

### 2. Quick Installation

**Option A: Automated Build (Recommended)**
```bash
# Clone the repository
git clone https://github.com/yourusername/code-review-app.git
cd code-review-app

# Run the automated build script
python build.py
```

**Option B: Manual Installation**
```bash
# Clone and enter directory
git clone https://github.com/yourusername/code-review-app.git
cd code-review-app

# Create virtual environment
python -m venv .venv
source .venv/bin/activate  # On Windows: .venv\Scripts\activate

# Install Python dependencies
pip install -r requirements.txt

# Build C++ performance module
python setup.py build_ext --inplace

# Run the application
python app.py
```

### 3. First Run

1. **Launch the application:**
   ```bash
   python app.py
   # OR use the generated run scripts:
   ./run.sh        # Unix/Linux/macOS
   # run.bat       # Windows
   ```

2. **Test LLM connection:** Click the "🔗 Test LLM" button to verify Ollama is running

3. **Select a Python file:** Click "📂 Select File" and choose a `.py` file

4. **Get code review:** Click "🔍 Review Code" and watch the analysis stream in real-time

5. **Ask follow-up questions:** Use the input box to ask specific questions about the code

---

## Configuration

The application supports flexible configuration through multiple methods:

### Environment Variables
```bash
export OLLAMA_API_URL="http://localhost:11434/api/chat"
export MODEL_NAME="qwen2.5-coder"
export BUFFER_SIZE=20
export FLUSH_INTERVAL_MS=100
export UI_THEME="dark"
export LOG_LEVEL="INFO"
```

### Configuration File
The app creates `~/.code_review_app/config.json`:
```json
{
  "ollama_api_url": "http://localhost:11434/api/chat",
  "model_name": "qwen2.5-coder",
  "buffer_size": 20,
  "flush_interval_ms": 100,
  "max_conversation_length": 50000,
  "ui_theme": "dark",
  "window_width": 1200,
  "window_height": 800
}
```

---

## Usage Examples

### Basic Code Review
1. Select a Python file with the file picker
2. Click "Review Code" to get comprehensive analysis
3. View real-time streaming results with syntax highlighting

### Interactive Follow-up
```
User: "How can I improve the performance of this function?"
Assistant: [Detailed performance analysis with specific suggestions]

User: "Show me an example of the optimization you mentioned"
Assistant: [Code example with explanations]
```

### Advanced Features
- **Theme Toggle:** Switch between light and dark modes
- **Progress Tracking:** Real-time status updates during processing
- **Error Recovery:** Automatic retry with exponential backoff
- **Connection Testing:** Verify LLM service availability

---

## Development

### Building from Source

**Install Development Dependencies:**
```bash
pip install -r requirements.txt
pip install pytest pytest-qt black flake8  # Additional dev tools
```

**Build C++ Components:**
```bash
# Using CMake (preferred)
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .

# OR using setup.py
python setup.py build_ext --inplace
```

**Run Tests:**
```bash
pytest tests/                    # Unit tests
python -m pytest --qt-gui       # GUI tests
```

**Code Formatting:**
```bash
black .                          # Format Python code
flake8 .                         # Check code style
```

### Performance Profiling

The application includes built-in performance monitoring:

```python
# Enable performance logging
export LOG_LEVEL=DEBUG

# Monitor with built-in tools
import psutil
import memory_profiler
```
