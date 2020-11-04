//Book 1
//2.3 Adding a Progress Indicator

#include <iostream>
using std::cout;
using std::cerr;
int main() {
    //Image
    const int image_width=256;
    const int image_height=256;

    //Render
    cout<<"P3\n"<<image_width<<" "<<image_height<<"\n255\n";

    for (int j=image_height-1; j>=0; j--) {
        cerr<<"\rScanlines remaining: "<<j<<"\n";
        for (int i=0; i<image_width; i++) {
            auto r=1.0*i/(image_width-1);
            auto g=1.0*j/(image_width-1);
            auto b=0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            cout<<ir<<" "<<ig<<" "<<ib<<"\n";
        }
    }

    cerr<<"\nDone.\n";

    return 0;
}