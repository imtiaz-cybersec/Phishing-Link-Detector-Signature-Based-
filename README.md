# 🛡️ PhishDetect: Signature-Based Phishing Link Detector (C++)

This project is a **signature-based phishing link detector** written in C++. It scans URLs and detects potentially malicious links based on known phishing signatures.

## 🔍 Features

- Detects suspicious domains and keywords in URLs
- Compares against a signature list of phishing patterns
- Lightweight, fast, and runs from the command line
- Useful for students and analysts learning basic detection concepts

## 🧠 How It Works

The detector uses a list of **predefined phishing link patterns** (signatures) and checks if the given URL matches any known suspicious indicators.

Examples of phishing indicators:
- Use of IP addresses instead of domain names
- Suspicious subdomains (e.g., `paypal.login.security.com`)
- Use of `@` symbols or long redirect chains

## 📁 Project Structure

phishdetect/
├── detector.cpp # Main C++ detection code
├── signatures.txt # List of known phishing patterns
├── reports/
│ └── project-report.pdf
├── slides/
│ └── phishing-detector-presentation.pptx
├── README.md

## 🖥️ How to Run

1. Compile the code:
   ```bash
   g++ detector.cpp -o phishdetect
