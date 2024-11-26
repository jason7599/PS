#include <iostream>

int main() {
    int n;
    std::cin>>n;

    int *height = new int[n];
    for(int i=0; i<n; i++)
        std::cin>>height[i];

    int count,max=0;
    for(int i=0; i<n; i++) {
        count=0;
        if(i+1!=n) {
            for(int j=i+1; j<n; j++) {
                if(height[i]<height[j]) break;
                count++;
            }
        }
        if(max<count) max=count;
    }

    std::cout<<max;
    delete[] height;
}