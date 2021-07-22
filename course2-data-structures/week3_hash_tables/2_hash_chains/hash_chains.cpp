#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::string;
using std::vector;
using std::cin;
using std::unordered_map;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    // vector<string> elems;
    unordered_map<unsigned long long, vector<string>> elems;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {}

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            // use reverse order, because we append strings to the end
            if (elems.find(query.ind) != elems.end()) {
                int i = elems[query.ind].size() - 1;
                string str = "";
                while(i >= 0) {        
                    str += elems[query.ind][i] + " ";
                    i--;
                }
                str.erase(str.size() - 1);
                std::cout << str << " ";                
            } else {
                std::cout << " ";
            }
            std::cout << "\n";
        } else {
            auto key = hash_func(query.s);
            if (query.type == "find") {
                if (elems.find(key) != elems.end()) {
                    auto it = find(elems[key].begin(), elems[key].end(), query.s);
                    if ( it != elems[key].end()) 
                        writeSearchResult(true);
                    else
                        writeSearchResult(false);
                } else {
                    writeSearchResult(false);
                }
            } else if (query.type == "add") {
                if (elems.find(key) == elems.end())
                    elems[key].push_back(query.s);
                else {
                    if (find(elems[key].begin(), elems[key].end(), query.s) == elems[key].end()) {
                        elems[key].push_back(query.s);
                    }
                }

            } else if (query.type == "del") {
                if (elems.find(key) != elems.end()) {
                    auto it = find(elems[key].begin(), elems[key].end(), query.s);
                    if ( it != elems[key].end())
                        elems[key].erase(it);
                    if (elems[key].empty())
                        elems.erase(key);
                }
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
