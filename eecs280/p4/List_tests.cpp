// Project UID c1f28c309e55405daf00c565d57ff9ad

#include "List.h"
#include "unit_test_framework.h"

using namespace std;

// Add your test cases here

TEST(test_stub) {
    // Add test code here
    List<int> list1;
    ASSERT_TRUE(list1.size() == 0);

    for (int i = 1; i< 3; ++i) {
        list1.push_back(i);
    }
    List<int> list2;
    ASSERT_TRUE(list2.empty());
    list2 = list1;
    ASSERT_TRUE(list1.size() == 2);
    ASSERT_TRUE(list2.size() == 2);
    ASSERT_TRUE(list1.front() == 1);
    ASSERT_TRUE(list2.front() == 1);
    List<int> list3(list2);
    ASSERT_TRUE(list3.size() == 2);
    ASSERT_TRUE(list3.front() == 1);
    ASSERT_TRUE(list2.back() == 2);
    ASSERT_TRUE(!list1.empty());
    for (int i = 1; i< 3; ++i) {
        list1.push_front(i);
    }
    list1.push_back(5);
    ASSERT_TRUE(list1.size() == 5);
    ASSERT_TRUE(list1.front() == 2);
    ASSERT_TRUE(list1.back() == 5);
    list1.pop_front();
    ASSERT_TRUE(list1.size() == 4);
    ASSERT_TRUE(list1.front() == 1);
    ASSERT_TRUE(list1.back() == 5);
    list1.pop_back();
    ASSERT_TRUE(list1.size() == 3);
    ASSERT_TRUE(list1.front() == 1);
    ASSERT_TRUE(list1.back() == 2);
    list1.clear();
    ASSERT_TRUE(list1.empty());
}

TEST(test_iterators) {
    List<int> list1;
    List<int>::Iterator it1 = list1.begin();
    List<int>::Iterator it2 = list1.end();
    List<int>::Iterator it3 = it1;
    List<int>::Iterator it4(it2);
    ASSERT_TRUE(it1 == it3);
    ASSERT_TRUE(it2 == it4);
    ASSERT_TRUE(it1 == it2);
    list1.insert(it2, 2);
    list1.insert(list1.begin(), 3);
    ASSERT_TRUE(list1.front() == 3);
    ASSERT_TRUE(list1.back() == 2);
    it1 = list1.begin();
    ASSERT_TRUE(*it1 == 3);
    ++it1;
    ++it1;
    ASSERT_TRUE(it1 == list1.end());
    list1.erase(++list1.begin());
    ASSERT_TRUE(list1.size() == 1);
    ASSERT_TRUE(list1.front() == 3);
    ASSERT_TRUE(list1.back() == 3);
    list1.erase(list1.begin());
    ASSERT_TRUE(list1.empty());
    for (int i = 0; i< 3; ++i) {
        list1.push_front(i);
    }
    list1.erase(++list1.begin());
    ASSERT_TRUE(*++list1.begin() == 0);
    list1.erase(list1.begin());
    ASSERT_TRUE(*list1.begin() == 0);
    ASSERT_TRUE(list1.back() == 0);
    for (int i = 0; i< 3; ++i) {
        list1.push_front(i);
    }
    it1 = ++list1.begin();
    list1.insert(++it1, 666);
    ASSERT_TRUE(*++++list1.begin() == 666);
}

TEST_MAIN()
