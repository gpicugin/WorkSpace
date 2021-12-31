//#include <iostream>
//#include <vector>
//#include <set>
//using namespace std;
//
//vector<int> numbers = { 0, 1, 3, 3, 1, 3, 17, 0, 2, 3, 7, 1, 1, 1, 17, 0 };
//set<int> setOfNumbers;
//vector<int> result = { 0, 1, 3, 17, 2, 7 };
//// Objective:
//// Remove duplicate values from 'numbers' with preserving the relative
//// order of remaining items.
//
//void sol1()
//{
//    vector<int>::iterator pfront = numbers.begin() + 1;
//    vector<int>::iterator pback = numbers.begin();
//
//    while (pfront != numbers.end())
//    {
//        bool flag = false;
//        pback = pfront - 1;
//        while (pback != numbers.begin()) // TODO do-while
//        {
//            if (*pback != *pfront)
//                pback--;
//            else
//            {
//                pfront = numbers.erase(pfront);
//                flag = true;
//                break;
//            }
//        }
//        if (flag)
//            continue;
//        if (*pback != *pfront)
//        {
//        }
//        else
//        {
//            pfront = numbers.erase(pfront);
//            continue;
//        }
//        pfront++;
//    }
//}
//
//void sol2()
//{
//    std::set<int> set_numbers;
//    std::vector<int>::iterator p = numbers.begin();
//    std::pair<set<int>::iterator, bool> flag;
//    while (p != numbers.end())
//    {
//        flag = set_numbers.insert(*p);
//        if (flag.second)
//        {
//            p++;
//            continue;
//        }
//        else
//            p = numbers.erase(p);
//    }
//}
//
//void main()
//{
//    sol2();
//    if (numbers != result)
//        cout << "false\n";
//    else
//        cout << "true\n";
//}
//
