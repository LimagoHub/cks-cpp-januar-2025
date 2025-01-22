#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <random>
#include <iterator>

class Schwein
{
private:
    std::string name;
    int gewicht;
public:
    Schwein(std::string name = "Nobody") :name(name),gewicht(10) {}

    void fressen()
    {
        gewicht++;
    }
    std::string get_name() const
    {
        return name;
    }

    void set_name(const std::string& name)
    {
        this->name = name;
    }

    int get_gewicht() const
    {
        return gewicht;
    }

    void set_gewicht(int gewicht)
    {
        this->gewicht = gewicht;
    }


    friend bool operator==(const Schwein& lhs, const Schwein& rhs)  noexcept
    {
        return lhs.name == rhs.name	&& lhs.gewicht == rhs.gewicht;
    }

    friend bool operator!=(const Schwein& lhs, const Schwein& rhs)
    {
        return !(lhs == rhs);
    }


    /*std::size_t hash(const Schwein& obj) const noexcept
    {
        std::hash<std::string> str_hash;
        std::hash<int> int_hash;
        return str_hash (obj.get_name()) * int_hash(obj.gewicht);


    }
    */

    friend std::ostream& operator<<(std::ostream& os, const Schwein& obj)
    {
        return os
                << "name: " << obj.name
                << " gewicht: " << obj.gewicht;
    }
};

struct PigEqual {
public:
    bool operator()(const Schwein& str1, const Schwein& str2) const {
        return str1.get_name() == str2.get_name() && str1.get_gewicht() == str2.get_gewicht();
    }
};

struct PigHash {
public:
    size_t operator()(const Schwein& obj) const {
        std::hash<std::string> str_hash;
        std::hash<int> int_hash;
        return str_hash(obj.get_name()) * int_hash(obj.get_gewicht());
    }
};

class Sum {
    int sum{0};
    int count{0};

public:
    auto operator()(int n) -> void {
        sum += n;
        count ++;
    }

    auto getSum() const->int {
        return sum;
    }

    int getCount() const {
        return count;
    }
    int getAvg() const {
        return sum / count;
    }
};


int main() {

    /*Schwein s1{"Miss piggy"};
    Schwein s2{"Babe"};
    Schwein s3{"Miss piggy"};

    std::unordered_set<std::reference_wrapper<Schwein>,PigHash,PigEqual> X{ std::ref(s1),std::ref(s2), std::ref(s3) };

    for (auto Y : X)
        if (Y.get().get_name() == "Miss piggy")
            Y.get().fressen();

    for (auto Y : X)
        std::cout << Y << std::endl;


    std::array<int, 40> myArray;
    std::vector<double> v{10.0,20.0,30.0,40.0};

    for(auto &item: v){
        item ++;
        std::cout << item << std::endl;
    }

    Sum s;

    s = std::for_each(v.begin(), v.end(),s );
    std::cout << s.getSum() << std::endl;

     */

    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(v.begin(), v.end(), g);

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::sort(v.begin(), v.end(), [](int a, int b)
    {
        return a > b;
    });

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << std::endl;
    std::cout << '\n';
    return 0;
}

