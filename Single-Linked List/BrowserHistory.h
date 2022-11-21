#include <string>
using std::string;
class BrowserHistory {
    private:
        string homepage;
    public:
        BrowserHistory(string homepage);
        void visit(string url);
        string back(int steps);
        string forward(int steps);
};