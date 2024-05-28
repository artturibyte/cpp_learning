#include    <string>
#include    <iostream>
#include    <list>
#include    <algorithm>

using namespace std;

class URL{
    string protocol;
    string resource;

    public:
    URL(string p, string r): protocol(p), resource(r) {};

    void print_url() {
        cout<<protocol<<"://"<<resource<<endl;
    }

    string get_url() {
        return protocol + "://" + resource;
    }
};

class urlStore{
    list<URL> url_list;

    public:
    urlStore() = default;
    void store_url(URL new_url) {
        string new_url_s = new_url.get_url();

        auto old = find_if(begin(url_list), end(url_list), [&new_url_s](URL u){return u.get_url() == new_url_s;});

        if (old != end(url_list)) {
            url_list.erase(old);
        }

        url_list.push_front(new_url);
    }

    void print_history() {
        for (auto url : url_list) {
            cout<<url.get_url()<<", ";
        }
        cout<<endl;
    }
};

int main(int argc, char const *argv[])
{
    URL u{"http", "www.a.com"};
    URL u2{"http", "www.b.com"};
    URL u3{"http", "www.c.com"};

    urlStore us;
    us.store_url(u);
    us.store_url(u2);
    us.store_url(u3);
    us.print_history();

    us.store_url(u);
    us.print_history();
    
    return 0;
}
