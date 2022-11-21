#include <string>
#include "BrowserHistory.h"
using std::string;

BrowserHistory::BrowserHistory(string homepage) : homepage{homepage} {};

void BrowserHistory::visit(string url) {
    return;
}

string BrowserHistory::back(int steps) {
    return "";
}

string BrowserHistory::forward(int steps) {
    return "";
}
