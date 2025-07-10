#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

vector<string> phishingDomains = {".xyz", ".tk",".show" ".cf", ".ga", ".ml", ".top", ".gq"};

vector<string> suspiciousWords = {"g00gle", "faceb00k", "amaz0n", "pay-pal", "bank-login", "secure-verification"};

bool hasPhishingDomain(string url) {
    for (string domain : phishingDomains) {
        if (url.find(domain) != string::npos) {
            return true;
        }
    }
    return false;
}

bool hasSuspiciousWords(string url) {
    for (string word : suspiciousWords) {
        if (url.find(word) != string::npos) {
            return true;
        }
    }
    return false;
}

bool hasTooManyDashes(string url) {
    int dashCount = 0;
    for (char c : url) {
        if (c == '-' || c == '_') {
            dashCount++;
        }
    }
    return dashCount > 2; 
}

bool hasAtSymbol(string url) {
    return url.find('@') != string::npos;
}

bool isIPAddress(string url) {
    regex ipPattern("(\\b(?:[0-9]{1,3}\\.){3}[0-9]{1,3}\\b)");
    return regex_search(url, ipPattern);
}

int calculateRiskScore(string url) {
    int score = 0;
    if (hasPhishingDomain(url)) score += 4;
    if (hasSuspiciousWords(url)) score += 4;
    if (hasTooManyDashes(url)) score += 3;
    if (hasAtSymbol(url)) score += 3;
    if (isIPAddress(url)) score += 5;
    
    return min(score, 10);
}

int main() {
    string url;
    cout << "?? Phishing Link Detector ??\n";
    cout << "Enter a URL to check: ";
    cin >> url;

    int riskScore = calculateRiskScore(url);

    cout << "\n?? Analyzing the URL...\n";

    if (riskScore >= 6) {
        cout << "?? Warning: This link is **HIGHLY DANGEROUS**! ??\n";
    } else if (riskScore >= 5) {
        cout << "?? Caution: This link looks **SUSPICIOUS**.\n";
    } else {
        cout << "? Safe: This link appears **legitimate**.\n";
    }
    
    cout << "Phishing Risk Score: " << riskScore << "/10\n";
    return 0;}
