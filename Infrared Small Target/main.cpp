#include"Functions Define and Header Files.h"
//����ȫ�ֱ���
Mat g_srcImage, g_dstImage;//ԭʼͼ��Ч��ͼ
int g_nElementShape = MORPH_RECT;//Ԫ�ؽṹ����״

  //�������յ�TrackBarλ�ò���
int g_nMaxIterationNum = 10;
int g_nTopHatNum = 0;

//����ȫ�ֺ���
static void on_TopHat(int, void*);//�ص�����

int main()
{
	//����ԭͼ
	g_srcImage = imread("3.jpg");  //����Լ�ͼ���·�� 
	imshow("��ԭʼͼ��", g_srcImage);

	//�����������
	namedWindow("����ñ��", 1);
	//������ֵ
	g_nTopHatNum = 2;
	//Ϊ���ڴ���������
	createTrackbar("����ֵ", "����ñ��", &g_nTopHatNum, g_nMaxIterationNum * 2 + 1, on_TopHat);
	//ִ�лص�����
	on_TopHat(g_nTopHatNum, 0);

	waitKey(0);
	return 0;
}

//on_nTopHat()����
static void on_TopHat(int, void*)
{
	//ƫ�����Ķ���
	//int offset = g_nTopHatNum - g_nMaxIterationNum;//ƫ����
	//int Absolute_offset = offset > 0 ? offset : -offset;//ƫ��������ֵ
	//�Զ����
	Mat element = getStructuringElement(g_nElementShape, Size(g_nTopHatNum * 2 + 1, g_nTopHatNum * 2 + 1));
	//���в���
	morphologyEx(g_srcImage, g_dstImage, MORPH_TOPHAT, element);

	imshow("����ñ��", g_dstImage);
}