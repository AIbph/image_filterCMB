#include<opencv2/opencv.hpp>
#include<iostream>
#include <math.h>
using namespace cv;
Mat src, dst;

int main(int argc, char** argv){
	// �Զ��������˲�
	
	// ��ȡͼƬ
	src = imread("D:/OpenCVProject/day1214/�Զ��������˲�/�Զ��������˲�/test.jpg");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	imshow("origin image", src);

	// �����ľ������
	// Robert����X����
	Mat rot_x = (Mat_<int>(2, 2) << 1, 0, 0, -1);

	// Robert����Y����
	Mat rot_y = (Mat_<int>(2, 2) << 0, 1, -1, 0);

	// Sobel����X����
	Mat sob_x = (Mat_<int>(3, 3) << -1, 0, 1, -2, 0, -2, -1, 0, 1);

	// Sobel����Y����
	Mat sob_y = (Mat_<int>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);

	// ������˹����
	Mat lpl = (Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);

	// ���ģ��		//filter2D(src, dst, src.depth(), lpl);
	//imshow("filtered image", dst);

	// ��ӱ�Ե����һ��BORDER_DEFAULT
	//copyMakeBorder(src, dst, 10, 10, 10, 10, BORDER_DEFAULT);
	//imshow("BORDER_DEFAULT image", dst);

	// ��ӱ�Ե��������BORDER_CONSTANT������Ե��ָ������ֵ��
	//Scalar color = Scalar(0, 0, 255);
	//copyMakeBorder(src, dst, 10, 10, 10, 10, BORDER_CONSTANT, color);
	//imshow("BORDER_CONSTANT image", dst);

	// ��ӱ�Ե��������BORDER_REPLICATE������Ե��������֪�ı�Ե����ֵ��
	//copyMakeBorder(src, dst, 10, 10, 10, 10, BORDER_REPLICATE);
	//imshow("BORDER_REPLICATE image", dst);

	// ��ӱ�Ե��������BORDER_WRAP��������һ�ߵ�������������䣩
	//copyMakeBorder(src, dst, 10, 10, 10, 10, BORDER_WRAP);
	//imshow("BORDER_WRAP image", dst);


	copyMakeBorder(src, src, 10, 10, 10, 10, BORDER_DEFAULT);
	imshow("first image", src);
	filter2D(src, dst, src.depth(), lpl);
	imshow("filtered image", dst);

	waitKey(0);
	return 0;
}