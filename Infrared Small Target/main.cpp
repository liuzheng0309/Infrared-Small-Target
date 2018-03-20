#include"Functions Define and Header Files.h"
//声明全局变量
Mat g_srcImage, g_dstImage;//原始图和效果图
int g_nElementShape = MORPH_RECT;//元素结构的形状

  //变量接收的TrackBar位置参数
int g_nMaxIterationNum = 10;
int g_nTopHatNum = 0;

//声明全局函数
static void on_TopHat(int, void*);//回调函数

int main()
{
	//载入原图
	g_srcImage = imread("3.jpg");  //存放自己图像的路径 
	imshow("【原始图】", g_srcImage);

	//创建输出窗口
	namedWindow("【顶帽】", 1);
	//参数赋值
	g_nTopHatNum = 2;
	//为窗口创建滚动条
	createTrackbar("迭代值", "【顶帽】", &g_nTopHatNum, g_nMaxIterationNum * 2 + 1, on_TopHat);
	//执行回调函数
	on_TopHat(g_nTopHatNum, 0);

	waitKey(0);
	return 0;
}

//on_nTopHat()函数
static void on_TopHat(int, void*)
{
	//偏移量的定义
	//int offset = g_nTopHatNum - g_nMaxIterationNum;//偏移量
	//int Absolute_offset = offset > 0 ? offset : -offset;//偏移量绝对值
	//自定义核
	Mat element = getStructuringElement(g_nElementShape, Size(g_nTopHatNum * 2 + 1, g_nTopHatNum * 2 + 1));
	//进行操作
	morphologyEx(g_srcImage, g_dstImage, MORPH_TOPHAT, element);

	imshow("【顶帽】", g_dstImage);
}