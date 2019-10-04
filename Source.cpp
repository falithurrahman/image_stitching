#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main() {
	Mat gambarA, gambarB, gambarArgb, gambarBrgb;
	Mat templ;
	gambarA = imread("gambarA2.jpg", IMREAD_GRAYSCALE);
	gambarB = imread("gambarB2.jpg", IMREAD_GRAYSCALE);
	//gambarA = imread("gambarA2.jpg");
	//gambarB = imread("gambarB2.jpg");
	//gambarA = imread("gambarg.jpg", IMREAD_GRAYSCALE);
	//gambarB = imread("gambarh.jpg", IMREAD_GRAYSCALE);
	//gambarA = imread("gambarg.jpg");
	//gambarB = imread("gambarh.jpg");
	//resize(gambarA, gambarA, Size(300, 300));
	//resize(gambarB, gambarB, Size(300, 300));

	double min, max;
	Point minloc, maxloc;
	Point locA, locB;
	Scalar intensity;
	int ukuran = 100;
	//if (gambarA.empty() && gambarB.empty()) break;

	//cout << gambarA.rows << "," << gambarA.cols << endl;
	//Mat hasil(Size(1000, 1000), CV_32F);

	for (int baris = 0; baris < gambarA.rows - ukuran; baris = baris + ukuran) {
		for (int kolom = 0; kolom < gambarA.cols - ukuran; kolom = kolom + ukuran) {
			Mat templ = gambarA(Rect(kolom, baris, ukuran, ukuran));
			//Rect roi(kolom, baris, 99, 99);
			//templ = gambarA(roi);
			//imwrite("templ1.jpg", templ);
			//templ = imread("templ1.jpg", IMREAD_GRAYSCALE);
			Mat hasil((gambarB.rows - templ.rows + 1), (gambarB.cols - templ.rows + 1), CV_32F);

			matchTemplate(gambarB, templ, hasil, TM_SQDIFF_NORMED);
			minMaxLoc(hasil, &min, &max, &minloc, &maxloc);
			//cout << min << endl;

				if (min < 0.04) {
					locA.x = kolom;
					locA.y = baris;
					locB.x = minloc.x;
					locB.y = minloc.y;
					break;
				}
		}
		if (min < 0.04)break;
	}

		//Mat wadah((locA.x - gambarB.cols + locB.x), (locA.y - gambarB.rows + locB.y), CV_32F);
	//Mat wadah(768, 1366, CV_8UC1);
	Mat wadah((locA.y + gambarB.rows - locB.y), (locA.x + gambarB.cols - locB.x), CV_8UC1);

	for (int y = 0; y < gambarA.rows; y++)
	{
		for (int x = 0; x < gambarA.cols; x++)
		{
			// get pixel
			intensity = gambarA.at<uchar>(y, x);
			//
			
			wadah.at<uchar>(y,x) = intensity.val[0];

			//wadah.at<Vec3b>(y, x) = gambarA.at<Vec3b>(y, x);
		}
	}

	for (int m = 0; m < gambarB.rows; m++)
	{
		for (int n = 0; n < gambarB.cols; n++)
		{
			// get pixel
			intensity = gambarB.at<uchar>(m,n);

			wadah.at<uchar>(m+abs(locB.y-locA.y),n+abs(locB.x - locA.x)) = intensity.val[0];

			//wadah.at<Vec3b>(m + abs(locB.y - locA.y), n + abs(locB.x - locA.x)) = gambarB.at<Vec3b>(m, n);
		}
	}
	//circle(wadah, locB, 5, Scalar(255, 0, 0), -1);
	imshow("gambarA", gambarA);
	imshow("gambarB", gambarB);
	imshow("wadah", wadah);
	waitKey(0);
	return 0;
}