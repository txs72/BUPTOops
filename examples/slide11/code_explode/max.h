#include <iostream>

using namespace std;

/* extern template <typename T> inline T const& Max (T const& a, T const& b); */
template <typename T>
inline T const& Max (T const& a, T const& b) { 
    T arr[10];
    for(int i=0;i<10;i++){
        arr[i] = a;
        cout << arr[i] << endl;
    }
    return a < b ? b:a; 
}
