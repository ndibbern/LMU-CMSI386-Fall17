#include <cassert>
#include <string>
#include <iostream>

using namespace std;

class Say {
    string phrase;

    public:
        Say(string first_word = ""): phrase(first_word) {}
        auto operator()(string new_word) {
            string longer_phrase = phrase;
            if (phrase != "") longer_phrase += ' ';
            longer_phrase += new_word;
            Say say_more(longer_phrase);
            return say_more;
        }
        auto operator()() {
            // overload with the case that no param was passed should end call chain
            return phrase;
        }
};

int main() {
    Say say; // Say say("first_word")
    assert(say() == "");
    assert(say("hi")() == "hi");
    assert(say("hi")("there")() == "hi there");
    assert(say("hello")("my")("name")("is")("Colette")() == "hello my name is Colette");

    // cout << say("hello")() << '\n';
    // cout << say("hello")("my")("friend")() << '\n';
    // cout << say("hello")("my")("name")("is")("Colette")() << '\n';
}
