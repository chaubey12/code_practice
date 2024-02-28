#include <iostream>
#include <vector>
#include <sstream>
#include <memory>

using namespace std;

enum class OutputFormat{
    markdown,
    html
};

struct ListStrategy{
    virtual void start(ostringstream& oss){}
    virtual void add_list_item(ostringstream& oss, const string& item) = 0;
    virtual void end(ostringstream& oss){}
};

struct MarkdownListStrategy : ListStrategy{
    void add_list_item(ostringstream &oss, const string &item) override{
        oss << "* "<<item << endl;
    }
};

struct HtmlListStrategy : ListStrategy{
    void start(ostringstream& oss) override{
        oss << "<ul>"<<endl;
    }
    void add_list_item(ostringstream& oss, const string& item) override{
        oss << "    <li>"<< item <<"</li>"<<endl;
    }
    void end(ostringstream& oss) override{
        oss << "</ul>"<<endl;
    }
};

template <typename LS>
struct TextProcessor{
    void clear(){
        oss.str("");
        oss.clear();
    }
    void append_list(const vector<string>& items){
        list_strategy.start(oss);
        for(auto& item : items){
            list_strategy.add_list_item(oss, item);
        }
        list_strategy.end(oss);
    }
    string str() const { return oss.str(); }
private:
    ostringstream oss;
    LS list_strategy;
};

int main(){
    vector<string> items{"foo", "bar", "baz"};
    // markdown
    TextProcessor<MarkdownListStrategy> tpm;
    tpm.append_list(items);
    cout << tpm.str() << endl;
    // html
    TextProcessor<HtmlListStrategy> tph;
    tph.append_list(items);
    cout << tph.str() << endl;
    return 0;
}