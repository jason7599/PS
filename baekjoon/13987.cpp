#include <iostream>

bool has_camera[100'000];

int main()
{
    int n_houses, n_cameras, coverage;
    std::cin >> n_houses >> n_cameras >> coverage;

    while (n_cameras--)
    {
        int house_no;
        std::cin >> house_no;
        has_camera[house_no - 1] = 1;
    }

    int camera_cnt = 0;
    for (int i = 0; i < coverage - 1; i++)
        camera_cnt += has_camera[i];
    
    int n_cameras_required = 0;
    for (int l = 0; l + coverage <= n_houses; l++)
    {
        camera_cnt += has_camera[l + coverage - 1];

        for (int r = l + coverage - 1; camera_cnt < 2; r--)
        {
            if (!has_camera[r])
            {
                has_camera[r] = 1;
                camera_cnt++;
                n_cameras_required++;
            }
        }

        camera_cnt -= has_camera[l];
    }

    std::cout << n_cameras_required;
}