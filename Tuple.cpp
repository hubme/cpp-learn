#include <iostream>
#include <tuple>

using namespace std;

template <size_t Index, typename Tuple>
void printTupleElementType() {
    using ElementType = typename tuple_element<Index, Tuple>::type;
    cout << "Element " << Index << " 的类型是: " << typeid(ElementType).name() << endl;
}

int main(int argc, char const* argv[]) {
    // typedef tuple<int, double, string> MyTuple;
    using MyTuple = tuple<int, double, string>;
    MyTuple t = make_tuple(1, 2.5, "Hello");
    auto index0 = get<0>(t);
    auto index1 = get<1>(t);
    auto index2 = get<2>(t);
    cout << "Tuple elements: " << index0 << ", " << index1 << ", " << index2 << endl;
    int size = tuple_size<tuple<int, double, string>>::value;
    cout << "Tuple size: " << size << endl;

    using ElementType0 = typename tuple_element<0, MyTuple>::type;
    cout << "Element 0 的类型是: " << typeid(ElementType0).name() << endl;

    using ElementType1 = typename tuple_element<1, MyTuple>::type;
    cout << "Element 1 的类型是: " << typeid(ElementType1).name() << endl;

    using ElementType2 = typename tuple_element<2, MyTuple>::type;
    cout << "Element 2 的类型是: " << typeid(ElementType2).name() << endl;

    return 0;
}
