### Description

The idea of this project is to combine 2 picture comes with area of identical pixel to make bigger picture. IF you know the panorama feature of camera that nowaday's smartphones have, the idea of this project is quite similiar with it. For example take a look at two pictures below.

![picture 1](https://github.com/falithurrahman/image_stitching/blob/master/gambarB.jpg) ![picture 2](https://github.com/falithurrahman/image_stitching/blob/master/gambarB2.jpg)

As you can see, those picture have some identic area marked with red box. This area inside red box also has identic pixel. The idea is i match the first pixel of the picture on the bottom, with every pixel of the picture on the top. I scan every row and column of pixel from picture on the top, if i find identical pixel, i will mark the position of that pixel and "copy paste" the picture on the bottom to the picture on the top.

![picture 3](https://github.com/falithurrahman/image_stitching/blob/master/gambarBedited.jpg) ![picture 3](https://github.com/falithurrahman/image_stitching/blob/master/gambarB2edited.jpg)

I've attached the source code and image i used for this project in this repository. And you can see the result of this project at the image below. I am very open if you have anything in mind, just feel free to ask. Thanks.

![combined](https://github.com/falithurrahman/image_stitching/blob/master/combined.jpg)