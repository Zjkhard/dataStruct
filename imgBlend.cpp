#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<highgui.h>
#include<cv.h>
using namespace cv;

#define WINDOW_NAME "线性混合示例"   //"为窗口标题定义的宏"


const int g_nMaxAlphaValue = 100;  //Alpha 值得最大值
int g_nAlphaValueSlider;           //滑动条对应得变量
double g_dAlphaValue;
double g_dBetaValue;

//声明储存图像的变量
Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;


//响应滑动条的回调函数

void on_Trackbar(int, void*)
{
	//求出当前alpha值相对于最大值的比例
	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;

	//beta值为1 减去alpha 的值
	g_dBetaValue = (1.0 - g_dAlphaValue);
	//根据alpha 和 beta 值进行线性混合
	addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_dstImage);
	//显示效果图
	imshow(WINDOW_NAME,g_dstImage);
}




void example()
{

	//初级图像混合
	Mat  image = imread("3.jpg", 199);
	Mat  logo = imread("2.jpg");
	Mat dst;

	namedWindow("[3]原始图");
	imshow("[3]原始图", image);

	namedWindow("[2]logo图");
	imshow("[2]logo图", logo);


	//定义一个Mat类型 用于存放图像的ROI
	Mat imageROI;
	//方法一
	//imageROI = image(Rect(800, 350, logo.cols, logo.rows));

	//方法二
	//imageROI = image(Range(350, 350 + logo.rows), Range(800, 800 + logo.cols));

	//将logo加到原图
	addWeighted(logo, 0.8, image, 0.4, 0.0, dst);

	//显示结果
	//namedWindow("原画+logo图",1);
	imshow("原画+logo图", dst);

	//imwrite("由imwrite生成的图片.jpg", image);
}


int main()
{
	//第一张照片与第二张照片大小应一致
	g_srcImage1 = imread("2.jpg");
	g_srcImage2 = imread("3.jpg");

	if (!g_srcImage1.data)
	{
		printf("第一张照片读取错误");
		return -1;
	}
	if (!g_srcImage2.data)
	{
		printf("第二张照片读取错误");
		return -1;
	}

	//设置滑动条初值为70
	g_nAlphaValueSlider = 70;

	//创建窗体
	namedWindow(WINDOW_NAME, 1);

	//在创建的窗体中创建一个滑动条控件
	char TrackbarName[50];
	sprintf(TrackbarName, "透明值%d", g_nMaxAlphaValue);

	createTrackbar(TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);

	//结果在回调函数中显示
	on_Trackbar(g_nAlphaValueSlider, 0);

	
	//example();
	waitKey(10000);
	return 0;
}