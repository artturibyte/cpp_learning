#include    <algorithm>
#include    <iostream>
#include    <string>
#include    <vector>
#include    <random>
#include    <fstream>
#include    <iterator>
#include    <sstream>

template<class T>
void print(T vec) {
    for (auto i: vec) {
        std::cout<<i<<", ";
    }
    std::cout<<std::endl;
}

int main() {
    std::random_device rd;
    std::vector<int> vec1(10);
    std::mt19937 rand_gen(rd());

    std::uniform_int_distribution<int> idist(0, 1000);

    // 1. Fill a vector with 10 random integers between 0 and 1000
    std::generate(begin(vec1), end(vec1), [&idist, &rand_gen](){return idist(rand_gen);});
    std::cout<<"v1: ";
    print(vec1); 

    // 2. Find the maximum element in this vector
    auto max_el = std::max_element(cbegin(vec1), cend(vec1));
    std::cout<<"Biggest element: "<< *max_el <<"\n";

    // 3. Find the index of this maximum element
    std::cout<<"In pos: "<< std::distance(cbegin(vec1), max_el) + 1 <<"\n";

    // 4. Sum the elements of the vector
    int sum = std::accumulate(cbegin(vec1), cend(vec1), 0);
    std::cout<<"Sum of vec: "<< sum <<"\n";

    // 5. Count the number of odd numbers in the vector
    int count_odd = std::count_if(cbegin(vec1), cend(vec1), [](int i){return i %2 != 0;});
    std::cout<<"Odd number count: "<< count_odd <<"\n";

    // 6. Normalize the vector (divide all the elements by the largest.) 
    // Put the normalized elements into a vector of doubles, without setting the size of the output vector first.
    std::vector<double> vec2;
    std::transform(cbegin(vec1), cend(vec1), back_inserter(vec2), [&max_el](int i){return (double)i / (double)*max_el;});
    std::cout<<"v2: ";
    print(vec2);

    // 7. Make a sorted copy of the vector. Without using a functor or a lambda (or equivalent), find the first element greater than 455 and the number of elements > 455
    std::vector<int> vec_copy(vec1.size());
    std::partial_sort_copy(cbegin(vec1), cend(vec1), begin(vec_copy), end(vec_copy));
    std::cout<<"Copy and sorted v1: ";
    print(vec_copy);

    // 8. Make a sorted copy of the vector. Without using a functor or a lambda (or equivalent), 
    // find the first element greater than 455 and the number of elements > 455
    auto over_455 = std::upper_bound(cbegin(vec_copy), cend(vec_copy), 455);
    std::cout<<"First over 455: "<< *over_455 <<"\n";
    std::cout<<"Number of elements over 455: "<< std::distance(over_455, cend(vec_copy)) <<"\n";

    // 9. Copy all the odd numbers to a vector of doubles, without setting the size of the output vector first
    std::vector<double> vec_odd;
    std::copy_if(cbegin(vec1), cend(vec1), back_inserter(vec_odd), [](int i){return i %2 != 0;});
    std::cout<<"Odd vector: ";
    print(vec_odd);

    // 10. Sort the vector in descending order
    std::sort(begin(vec_odd), end(vec_odd), [](int i1, int i2){return i1 > i2;});
    std::cout<<"Odd vector descending: ";
    print(vec_odd);

    // 11. Randomly shuffle all but the first and the last element of the vector
    std::shuffle(begin(vec1) + 1, end(vec1) - 1, rand_gen);
    std::cout<<"Vec1 shuffled: ";
    print(vec1);

    // 12. Remove all the odd numbers from the vector
    std::remove_if(begin(vec_copy), end(vec_copy), [](int i){return i %2 != 0;});
    std::cout<<"Vec with odd removed: ";
    print(vec_copy);

    // 13. Write the remaining elements to a text file on a single line as a comma separated list, without a trailing comma
    std::ofstream ostrm("even_numbers.txt");
    std::ostream_iterator<int> osi{ostrm,", "};
    
    std::copy(cbegin(vec_copy), cend(vec_copy), osi);
    ostrm.close();
    std::cout<<std::endl;

    // 14. Read the file "words.txt". Display each distinct word once. Ignore punctuation and capitalization
    // Hint: look into std::istreambuf_iterator
    std::ifstream istrm("words.txt");
    std::string s;

    std::istreambuf_iterator<char> it{istrm}, end;
    std::copy(it, end, back_inserter(s));
    istrm.close();

    std::istringstream is{s};
    std::string word{""};

    std::vector<std::string> langVec;
    while (is >> word) {langVec.push_back(word);}

    // 15) Count the total number of words in the file
    int number_of_words = std::count_if(cbegin(langVec), cend(langVec), [](std::string s){return s.size() > 1;});
    std::cout<<"Number of words: "<<number_of_words<<"\n";

    // 16. Count the number of lines in the file
    int number_of_lines = std::count_if(cbegin(s), cend(s), [](char c){return c=='\n';});
     // Add +1 because first line is not counted
    std::cout<<"Number of lines: "<<number_of_lines + 1<<"\n";

    // 17. Count the number of characters in the file
    int number_of_chars = std::count_if(cbegin(s), cend(s), [](char c){return isalpha(c);});
    std::cout<<"Number of chars: "<<number_of_chars<<"\n";

    // 18. Read "words.txt" and "words2.txt". Display the words which are common to both files
    std::ifstream istrm2("words2.txt");

    std::vector<std::string> langVec2;
    std::istream_iterator<std::string> it2{istrm2}, end2;
    std::copy(it2, end2, back_inserter(langVec2));
    istrm2.close();
    
    std::vector<std::string> lv;

    std::sort(begin(langVec), langVec.end());
    std::sort(begin(langVec2), langVec2.end());

    std::set_intersection(cbegin(langVec), cend(langVec), cbegin(langVec2), cend(langVec2), back_inserter(lv));
    std::cout<<"Common words: ";
    print(lv);

    // 19. Calculate the factorial of 6 (6 x 5 x 4 x ... x 1)
    std::vector<int> v(6);
    std::iota(v.begin(), v.end(), 1);
    print(v);
 
    //int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    int product = std::accumulate(v.begin(), v.end(), 1, [](int i1, int i2){return i1 * i2;});
    std::cout<<"Factorial of 6 is:"<< product<<std::endl;

}