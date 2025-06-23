#include <iostream>
#include <pixel.hpp>
#include <rendering.hpp>
#include <ray.hpp>

int main()
{
    Image image;
    Viewport viewport;
	Camera camera;
    
   /* std::cout << "=== IMAGE DEBUG ===" << std::endl;
    std::cout << "Image width: " << image.width << std::endl;
    std::cout << "Image height: " << image.height << std::endl;
    std::cout << "Aspect ratio: " << image.aspectRatio << std::endl;

    std::cout << "\n=== VIEWPORT DEBUG ===" << std::endl;
    std::cout << "Viewport width: " << viewport.getWidth() << std::endl;
    std::cout << "Viewport height: " << viewport.getHeight() << std::endl;
    std::cout << "Horizontal vector: " << viewport.getHorizontalVector().x << " "
        << viewport.getHorizontalVector().y << " " << viewport.getHorizontalVector().z << std::endl;
    std::cout << "Vertical vector: " << viewport.getVerticalVector().x << " "
        << viewport.getVerticalVector().y << " " << viewport.getVerticalVector().z << std::endl;*/

    /*std::cout << "\n=== CAMERA DEBUG ===" << std::endl;
    std::cout << "Camera center: " << camera.getCamCenter().x << " "
        << camera.getCamCenter().y << " " << camera.getCamCenter().z << std::endl;*/

    Vec3<double> pixel_delta_u = viewport.getHorizontalVector() / image.width;
    Vec3<double> pixel_delta_v = viewport.getVerticalVector() / image.height;
    Vec3<double> pixel00_loc = viewport.getUpperLeftPointCoordinates() + (pixel_delta_u + pixel_delta_v) * 0.5;

    /*std::cout << "\n=== PIXEL POSITIONS DEBUG ===" << std::endl;
    std::cout << "Upper left: " << viewport.getUpperLeftPointCoordinates().x << " " << viewport.getUpperLeftPointCoordinates().y << " " << viewport.getUpperLeftPointCoordinates().z << std::endl;
    std::cout << "Pixel (0,0): " << pixel00_loc.x << " " << pixel00_loc.y << " " << pixel00_loc.z << std::endl;*/

    std::cout << "P3\n" << image.width << ' ' << image.height << "\n255\n";

    for (int j = 0; j < image.height; j++) {
        std::clog << "\rScanlines remaining: " << (image.height - j) << ' ' << std::flush;
        for (int i = 0; i < image.width; i++) {
            Vec3<double> pixelCenter = pixel00_loc + (pixel_delta_u * i) + (pixel_delta_v * j);
            Vec3<double> rayDirection = pixelCenter - camera.getCamCenter();
	        //std::cout << "Ray direction: " << rayDirection.x << rayDirection.y << '\n';
            Ray r(camera.getCamCenter(), rayDirection);
            r.computeColor();
            /*std::cout << "Pixel[" << i << "," << j << "]:" << std::endl;
            std::cout << "  Center: " << pixelCenter.x << " " << pixelCenter.y << " " << pixelCenter.z << std::endl;
            std::cout << "  Ray dir: " << rayDirection.x << " " << rayDirection.y << " " << rayDirection.z << std::endl;
            std::cout << "  Magnitude: " << rayDirection.magnitude() << std::endl;
            */
            if (rayDirection.magnitude() == 0) {
                std::cout << "  *** ZERO VECTOR DETECTED! ***" << std::endl;
            }
            paint(r.color());
        }
    }
    std::clog << "\rDone.                 \n";
    return EXIT_SUCCESS;
}
