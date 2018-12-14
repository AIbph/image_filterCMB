#include<opencv2/opencv.hpp>
#include<iostream>
#include <math.h>
using namespace cv;
Mat src, dst;

int main(int argc, char** argv){
	// 自定义线性滤波
	
	// 读取图片
	src = imread("D:/OpenCVProject/day1214/自定义线性滤波/自定义线性滤波/test.jpg");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	imshow("origin image", src);

	// 常见的卷积算子
	// Robert算子X方向
	Mat rot_x = (Mat_<int>(2, 2) << 1, 0, 0, -1);

	// Robert算子Y方向
	Mat rot_y = (Mat_<int>(2, 2) << 0, 1, -1, 0);

	// Sobel算子X方向
	Mat sob_x = (Mat_<int>(3, 3) << -1, 0, 1, -2, 0, -2, -1, 0, 1);

	// Sobel算子Y方向
	Mat sob_y = (Mat_<int>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);

	// 拉普拉斯算子
	Mat lpl = (Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);

	// 卷积模糊		//filter2D(src, dst, src.depth(), lpl);
	//imshow("filtered image", dst);

	// 添加边缘方法一：BORDER_DEFAULT
	//copyMakeBorder(src, dst, 10, 10, 10, 10, BORDER_DEFAULT);
	//imshow("BORDER_DEFAULT image", dst);

	// 添加边缘方法二：BORDER_CONSTANT（填充边缘用指定像素值）
	//Scalar color = Scalar(0, 0, 255);
	//copyMakeBorder(src, dst, 10, 10, 10, 10, BORDER_CONSTANT, color);
	//imshow("BORDER_CONSTANT image", dst);

	// 添加边缘方法三：BORDER_REPLICATE（填充边缘像素用已知的边缘像素值）
	//copyMakeBorder(src, dst, 10, 10, 10, 10, BORDER_REPLICATE);
	//imshow("BORDER_REPLICATE image", dst);

	// 添加边缘方法三：BORDER_WRAP（用另外一边的像素来补偿填充）
	//copyMakeBorder(src, dst, 10, 10, 10, 10, BORDER_WRAP);
	//imshow("BORDER_WRAP image", dst);


	copyMakeBorder(src, src, 10, 10, 10, 10, BORDER_DEFAULT);
	imshow("first image", src);
	filter2D(src, dst, src.depth(), lpl);
	imshow("filtered image", dst);

	waitKey(0);
	return 0;
}