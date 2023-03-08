xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 254;
 0.69198;-5.23361;-8.57804;,
 2.51298;-6.37574;-11.57187;,
 0.66173;-6.44599;-11.85049;,
 0.69198;-5.23361;-8.57804;,
 4.04931;-6.10976;-10.77492;,
 0.69198;-5.23361;-8.57804;,
 5.00514;-5.69402;-9.59751;,
 0.69198;-5.23361;-8.57804;,
 5.21513;-5.20053;-8.24312;,
 0.69198;-5.23361;-8.57804;,
 4.64299;-4.71448;-6.94602;,
 0.69198;-5.23361;-8.57804;,
 3.38765;-4.32001;-5.93046;,
 0.69198;-5.23361;-8.57804;,
 1.66619;-4.08530;-5.37202;,
 0.69198;-5.23361;-8.57804;,
 -0.22379;-4.05089;-5.36728;,
 0.69198;-5.23361;-8.57804;,
 -1.95542;-4.22276;-5.91709;,
 0.69198;-5.23361;-8.57804;,
 -3.22933;-4.57120;-6.92633;,
 0.69198;-5.23361;-8.57804;,
 -3.82528;-5.03598;-8.22052;,
 0.69198;-5.23361;-8.57804;,
 -3.64014;-5.53672;-9.57587;,
 0.69198;-5.23361;-8.57804;,
 -2.70599;-5.98681;-10.75802;,
 0.69198;-5.23361;-8.57804;,
 -1.18435;-6.30847;-11.56260;,
 0.69198;-5.23361;-8.57804;,
 0.66173;-6.44599;-11.85049;,
 4.25404;-7.48848;-14.42728;,
 0.63243;-7.62600;-14.97235;,
 7.25961;-6.96815;-12.86826;,
 9.12947;-6.15486;-10.56483;,
 9.54025;-5.18940;-7.91529;,
 8.42099;-4.23854;-5.37779;,
 5.96518;-3.46679;-3.39103;,
 2.59746;-3.00762;-2.29859;,
 -1.09985;-2.94032;-2.28932;,
 -4.48747;-3.27658;-3.36489;,
 -6.97962;-3.95833;-5.33925;,
 -8.14544;-4.86753;-7.87105;,
 -7.78329;-5.84706;-10.52255;,
 -5.95581;-6.72759;-12.83521;,
 -2.97901;-7.35686;-14.40920;,
 0.63243;-7.62600;-14.97235;,
 5.79182;-11.25688;-16.01606;,
 0.55816;-11.45555;-16.80374;,
 10.13523;-10.50494;-13.76307;,
 12.83738;-9.32970;-10.43432;,
 13.43106;-7.93442;-6.60542;,
 11.81357;-6.56034;-2.93840;,
 8.31188;-2.71148;-1.07074;,
 3.44512;-2.04792;0.50800;,
 -1.89797;-1.95061;0.52136;,
 -6.79349;-2.43657;-1.03295;,
 -10.44223;-6.15533;-2.88272;,
 -12.12695;-7.46923;-6.54150;,
 -11.60361;-8.88488;-10.37319;,
 -8.96269;-10.15734;-13.71530;,
 -4.66082;-11.06666;-15.98992;,
 0.55816;-11.45555;-16.80374;,
 7.08235;-16.17295;-16.76182;,
 0.46534;-16.42417;-17.75770;,
 12.57379;-15.22221;-13.91333;,
 15.99014;-13.73638;-9.70477;,
 16.74074;-11.97232;-4.86384;,
 14.69574;-10.23511;-0.22754;,
 10.20876;-8.82508;3.40244;,
 4.05564;-7.98603;5.39843;,
 -2.69970;-7.86309;5.41533;,
 -8.88916;-8.47751;3.45021;,
 -13.44259;-9.72303;-0.15714;,
 -15.57260;-11.38425;-4.78299;,
 -14.91094;-13.17398;-9.62748;,
 -11.57199;-14.78278;-13.85294;,
 -6.13307;-15.93245;-16.72875;,
 0.46534;-16.42417;-17.75770;,
 8.17579;-20.30640;-16.30076;,
 0.46667;-20.51490;-17.49249;,
 14.56777;-19.57480;-12.86457;,
 18.53735;-18.44658;-7.77812;,
 19.39819;-17.11690;-1.92085;,
 17.00139;-15.81558;3.69446;,
 11.76143;-14.76772;8.09683;,
 4.58434;-14.15445;10.52509;,
 -3.28891;-14.08184;10.55934;,
 -10.49697;-14.56240;8.19370;,
 -15.79351;-15.51308;3.83718;,
 -18.26266;-16.76948;-1.75693;,
 -17.47752;-18.11432;-7.62135;,
 -13.57385;-19.31517;-12.74209;,
 -7.22663;-20.16429;-16.23371;,
 0.46667;-20.51490;-17.49249;,
 8.87623;-26.37530;-16.25795;,
 0.41019;-26.60426;-17.56668;,
 15.89578;-25.57187;-12.48438;,
 20.25512;-24.33286;-6.89852;,
 21.20047;-22.87264;-0.46615;,
 18.56835;-21.44357;5.70050;,
 12.81391;-20.29282;10.53510;,
 4.93213;-19.61931;13.20178;,
 -3.71417;-19.53955;13.23942;,
 -11.62996;-20.06732;10.64149;,
 -17.44649;-21.11131;5.85723;,
 -20.15809;-22.49109;-0.28613;,
 -19.29586;-23.96802;-6.72638;,
 -15.00890;-25.28673;-12.34987;,
 -8.03849;-26.21924;-16.18433;,
 0.41019;-26.60426;-17.56668;,
 9.20768;-32.70714;-15.49898;,
 0.35470;-32.94662;-16.86753;,
 16.54805;-31.86698;-11.55296;,
 21.10663;-30.57139;-5.71181;,
 22.09519;-29.04440;1.01454;,
 19.34276;-27.55004;7.46300;,
 13.32532;-26.34672;12.51858;,
 5.08332;-25.64242;15.30712;,
 -3.95811;-25.55900;15.34646;,
 -12.23567;-26.11090;12.62980;,
 -18.31806;-27.20262;7.62690;,
 -21.15359;-28.64543;1.20277;,
 -20.25196;-30.18988;-5.53179;,
 -15.76908;-31.56885;-11.41231;,
 -8.48008;-32.54399;-15.42200;,
 0.35470;-32.94662;-16.86753;,
 9.28543;-37.74390;-16.01190;,
 0.43366;-37.90987;-17.39875;,
 16.62186;-37.22979;-12.00311;,
 21.17439;-36.45656;-6.06552;,
 22.15589;-35.55790;0.77419;,
 19.39658;-34.68912;7.33339;,
 13.37359;-34.00049;12.47790;,
 5.12836;-33.61107;15.31822;,
 -3.91341;-33.58819;15.36320;,
 -12.18833;-33.93582;12.60510;,
 -18.26563;-34.59383;7.52082;,
 -21.09445;-35.44847;0.98943;,
 -20.18565;-36.35193;-5.85968;,
 -15.69642;-37.14804;-11.84225;,
 -8.40295;-37.69913;-15.92386;,
 0.43366;-37.90987;-17.39875;,
 8.89065;-43.94080;-16.25993;,
 0.42569;-44.09955;-17.58618;,
 15.90644;-43.44920;-12.42632;,
 20.25999;-42.70978;-6.74823;,
 21.19858;-41.85037;-0.20745;,
 18.55985;-41.01957;6.06506;,
 12.80012;-40.36104;10.98473;,
 4.91524;-39.98864;13.70091;,
 -3.73135;-39.96675;13.74394;,
 -11.64465;-40.29920;11.10637;,
 -17.45632;-40.92846;6.24430;,
 -20.16150;-41.74572;-0.00164;,
 -19.29245;-42.60972;-6.55142;,
 -14.99938;-43.37101;-12.27253;,
 -8.02469;-43.89802;-16.17574;,
 0.42569;-44.09955;-17.58618;,
 8.24541;-55.81082;-17.49578;,
 0.54380;-55.81082;-18.75255;,
 14.61532;-55.81082;-13.94281;,
 18.55217;-55.81082;-8.70793;,
 19.37519;-55.81082;-2.69632;,
 16.94209;-55.81082;3.05254;,
 11.67358;-55.81082;7.54462;,
 4.48062;-55.81082;10.00324;,
 -3.39304;-55.81082;10.00324;,
 -10.58597;-55.81082;7.54462;,
 -15.85449;-55.81082;3.05254;,
 -18.28758;-55.81082;-2.69632;,
 -17.46456;-55.81082;-8.70793;,
 -13.52775;-55.81082;-13.94281;,
 -7.15781;-55.81082;-17.49581;,
 0.54380;-55.81082;-18.75255;,
 7.15263;-55.85174;-15.61151;,
 0.54380;-55.85174;-16.68994;,
 12.61871;-55.85174;-12.56263;,
 15.99693;-55.85174;-8.07054;,
 16.70317;-55.85174;-2.91192;,
 14.61532;-55.85174;2.02123;,
 10.09438;-55.85174;5.87593;,
 3.92203;-55.85174;7.98569;,
 -2.83445;-55.85174;7.98569;,
 -9.00677;-55.85174;5.87593;,
 -13.52775;-55.85174;2.02123;,
 -15.61560;-55.85174;-2.91192;,
 -14.90936;-55.85174;-8.07054;,
 -11.53113;-55.85174;-12.56263;,
 -6.06503;-55.85174;-15.61151;,
 0.54380;-55.85174;-16.68994;,
 5.77099;-55.88559;-13.22916;,
 0.54380;-55.88559;-14.08215;,
 10.09438;-55.88559;-10.81767;,
 12.76636;-55.88559;-7.26469;,
 13.32495;-55.88559;-3.18451;,
 11.67358;-55.88559;0.71731;,
 8.09776;-55.88559;3.76619;,
 3.21578;-55.88559;5.43489;,
 -2.12821;-55.88559;5.43489;,
 -7.01015;-55.88559;3.76619;,
 -10.58597;-55.88559;0.71731;,
 -12.23737;-55.88559;-3.18454;,
 -11.67875;-55.88559;-7.26469;,
 -9.00677;-55.88559;-10.81767;,
 -4.68342;-55.88559;-13.22916;,
 0.54380;-55.88559;-14.08215;,
 4.16091;-55.91089;-10.45289;,
 0.54380;-55.91089;-11.04313;,
 7.15263;-55.91089;-8.78419;,
 9.00159;-55.91089;-6.32558;,
 9.38813;-55.91089;-3.50219;,
 8.24538;-55.91089;-0.80219;,
 5.77099;-55.91089;1.30758;,
 2.39277;-55.91089;2.46227;,
 -1.30516;-55.91089;2.46227;,
 -4.68342;-55.91089;1.30758;,
 -7.15781;-55.91089;-0.80219;,
 -8.30053;-55.91089;-3.50219;,
 -7.91399;-55.91089;-6.32558;,
 -6.06503;-55.91089;-8.78419;,
 -3.07334;-55.91089;-10.45289;,
 0.54380;-55.91089;-11.04313;,
 2.39277;-55.92654;-7.40404;,
 0.54380;-55.92654;-7.70573;,
 3.92203;-55.92654;-6.55104;,
 4.86715;-55.92654;-5.29427;,
 5.06475;-55.92654;-3.85104;,
 4.48062;-55.92654;-2.47089;,
 3.21578;-55.92654;-1.39243;,
 1.48893;-55.92654;-0.80219;,
 -0.40136;-55.92654;-0.80219;,
 -2.12818;-55.92654;-1.39243;,
 -3.39304;-55.92654;-2.47089;,
 -3.97718;-55.92654;-3.85104;,
 -3.77958;-55.92654;-5.29427;,
 -2.83442;-55.92654;-6.55104;,
 -1.30516;-55.92654;-7.40404;,
 0.54380;-55.92654;-7.70573;,
 0.54380;-55.93181;-4.21584;,
 0.54380;-55.93181;-4.21584;,
 0.54380;-55.93181;-4.21584;,
 0.54380;-55.93181;-4.21584;,
 0.54380;-55.93181;-4.21584;,
 0.54380;-55.93181;-4.21584;,
 0.54380;-55.93181;-4.21584;,
 0.54380;-55.93181;-4.21584;,
 0.54380;-55.93181;-4.21584;,
 0.54380;-55.93181;-4.21584;,
 0.54380;-55.93181;-4.21584;,
 0.54380;-55.93181;-4.21584;,
 0.54380;-55.93181;-4.21584;,
 0.54380;-55.93181;-4.21584;,
 0.54380;-55.93181;-4.21584;;
 
 225;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 3;13,14,12;,
 3;15,16,14;,
 3;17,18,16;,
 3;19,20,18;,
 3;21,22,20;,
 3;23,24,22;,
 3;25,26,24;,
 3;27,28,26;,
 3;29,30,28;,
 4;2,1,31,32;,
 4;1,4,33,31;,
 4;4,6,34,33;,
 4;6,8,35,34;,
 4;8,10,36,35;,
 4;10,12,37,36;,
 4;12,14,38,37;,
 4;14,16,39,38;,
 4;16,18,40,39;,
 4;18,20,41,40;,
 4;20,22,42,41;,
 4;22,24,43,42;,
 4;24,26,44,43;,
 4;26,28,45,44;,
 4;28,30,46,45;,
 4;32,31,47,48;,
 4;31,33,49,47;,
 4;33,34,50,49;,
 4;34,35,51,50;,
 4;35,36,52,51;,
 4;36,37,53,52;,
 4;37,38,54,53;,
 4;38,39,55,54;,
 4;39,40,56,55;,
 4;40,41,57,56;,
 4;41,42,58,57;,
 4;42,43,59,58;,
 4;43,44,60,59;,
 4;44,45,61,60;,
 4;45,46,62,61;,
 4;48,47,63,64;,
 4;47,49,65,63;,
 4;49,50,66,65;,
 4;50,51,67,66;,
 4;51,52,68,67;,
 4;52,53,69,68;,
 4;53,54,70,69;,
 4;54,55,71,70;,
 4;55,56,72,71;,
 4;56,57,73,72;,
 4;57,58,74,73;,
 4;58,59,75,74;,
 4;59,60,76,75;,
 4;60,61,77,76;,
 4;61,62,78,77;,
 4;64,63,79,80;,
 4;63,65,81,79;,
 4;65,66,82,81;,
 4;66,67,83,82;,
 4;67,68,84,83;,
 4;68,69,85,84;,
 4;69,70,86,85;,
 4;70,71,87,86;,
 4;71,72,88,87;,
 4;72,73,89,88;,
 4;73,74,90,89;,
 4;74,75,91,90;,
 4;75,76,92,91;,
 4;76,77,93,92;,
 4;77,78,94,93;,
 4;80,79,95,96;,
 4;79,81,97,95;,
 4;81,82,98,97;,
 4;82,83,99,98;,
 4;83,84,100,99;,
 4;84,85,101,100;,
 4;85,86,102,101;,
 4;86,87,103,102;,
 4;87,88,104,103;,
 4;88,89,105,104;,
 4;89,90,106,105;,
 4;90,91,107,106;,
 4;91,92,108,107;,
 4;92,93,109,108;,
 4;93,94,110,109;,
 4;96,95,111,112;,
 4;95,97,113,111;,
 4;97,98,114,113;,
 4;98,99,115,114;,
 4;99,100,116,115;,
 4;100,101,117,116;,
 4;101,102,118,117;,
 4;102,103,119,118;,
 4;103,104,120,119;,
 4;104,105,121,120;,
 4;105,106,122,121;,
 4;106,107,123,122;,
 4;107,108,124,123;,
 4;108,109,125,124;,
 4;109,110,126,125;,
 4;112,111,127,128;,
 4;111,113,129,127;,
 4;113,114,130,129;,
 4;114,115,131,130;,
 4;115,116,132,131;,
 4;116,117,133,132;,
 4;117,118,134,133;,
 4;118,119,135,134;,
 4;119,120,136,135;,
 4;120,121,137,136;,
 4;121,122,138,137;,
 4;122,123,139,138;,
 4;123,124,140,139;,
 4;124,125,141,140;,
 4;125,126,142,141;,
 4;128,127,143,144;,
 4;127,129,145,143;,
 4;129,130,146,145;,
 4;130,131,147,146;,
 4;131,132,148,147;,
 4;132,133,149,148;,
 4;133,134,150,149;,
 4;134,135,151,150;,
 4;135,136,152,151;,
 4;136,137,153,152;,
 4;137,138,154,153;,
 4;138,139,155,154;,
 4;139,140,156,155;,
 4;140,141,157,156;,
 4;141,142,158,157;,
 4;144,143,159,160;,
 4;143,145,161,159;,
 4;145,146,162,161;,
 4;146,147,163,162;,
 4;147,148,164,163;,
 4;148,149,165,164;,
 4;149,150,166,165;,
 4;150,151,167,166;,
 4;151,152,168,167;,
 4;152,153,169,168;,
 4;153,154,170,169;,
 4;154,155,171,170;,
 4;155,156,172,171;,
 4;156,157,173,172;,
 4;157,158,174,173;,
 4;160,159,175,176;,
 4;159,161,177,175;,
 4;161,162,178,177;,
 4;162,163,179,178;,
 4;163,164,180,179;,
 4;164,165,181,180;,
 4;165,166,182,181;,
 4;166,167,183,182;,
 4;167,168,184,183;,
 4;168,169,185,184;,
 4;169,170,186,185;,
 4;170,171,187,186;,
 4;171,172,188,187;,
 4;172,173,189,188;,
 4;173,174,190,189;,
 4;176,175,191,192;,
 4;175,177,193,191;,
 4;177,178,194,193;,
 4;178,179,195,194;,
 4;179,180,196,195;,
 4;180,181,197,196;,
 4;181,182,198,197;,
 4;182,183,199,198;,
 4;183,184,200,199;,
 4;184,185,201,200;,
 4;185,186,202,201;,
 4;186,187,203,202;,
 4;187,188,204,203;,
 4;188,189,205,204;,
 4;189,190,206,205;,
 4;192,191,207,208;,
 4;191,193,209,207;,
 4;193,194,210,209;,
 4;194,195,211,210;,
 4;195,196,212,211;,
 4;196,197,213,212;,
 4;197,198,214,213;,
 4;198,199,215,214;,
 4;199,200,216,215;,
 4;200,201,217,216;,
 4;201,202,218,217;,
 4;202,203,219,218;,
 4;203,204,220,219;,
 4;204,205,221,220;,
 4;205,206,222,221;,
 4;208,207,223,224;,
 4;207,209,225,223;,
 4;209,210,226,225;,
 4;210,211,227,226;,
 4;211,212,228,227;,
 4;212,213,229,228;,
 4;213,214,230,229;,
 4;214,215,231,230;,
 4;215,216,232,231;,
 4;216,217,233,232;,
 4;217,218,234,233;,
 4;218,219,235,234;,
 4;219,220,236,235;,
 4;220,221,237,236;,
 4;221,222,238,237;,
 3;224,223,239;,
 3;223,225,240;,
 3;225,226,241;,
 3;226,227,242;,
 3;227,228,243;,
 3;228,229,244;,
 3;229,230,245;,
 3;230,231,246;,
 3;231,232,247;,
 3;232,233,248;,
 3;233,234,249;,
 3;234,235,250;,
 3;235,236,251;,
 3;236,237,252;,
 3;237,238,253;;
 
 MeshMaterialList {
  6;
  225;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  0,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  0,
  0,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.180000;0.180000;0.180000;;
   0.155294;0.009412;0.000000;;
  }
  Material {
   0.800000;0.000000;0.047200;1.000000;;
   5.000000;
   0.330000;0.330000;0.330000;;
   0.550000;0.000000;0.032450;;
  }
  Material {
   0.621176;0.621176;0.621176;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.461176;0.000000;0.128627;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.392157;0.000000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  230;
  0.016220;0.938628;-0.344550;,
  0.016160;0.936397;-0.350569;,
  0.018185;0.936553;-0.350055;,
  0.019843;0.937062;-0.348600;,
  0.020885;0.937847;-0.346421;,
  0.021128;0.938760;-0.343924;,
  0.020513;0.939639;-0.341552;,
  0.019150;0.940348;-0.339675;,
  0.017292;0.940753;-0.338652;,
  0.015259;0.940790;-0.338646;,
  0.013378;0.940453;-0.339661;,
  0.011980;0.939797;-0.341524;,
  0.011326;0.938935;-0.343909;,
  0.011520;0.938016;-0.346401;,
  0.012527;0.937198;-0.348572;,
  0.014157;0.936625;-0.350046;,
  0.011725;0.737139;-0.675640;,
  0.133216;0.748131;-0.650041;,
  0.240715;0.784259;-0.571834;,
  0.313756;0.839098;-0.444378;,
  0.331010;0.898813;-0.287347;,
  0.258852;0.928217;-0.267225;,
  0.108102;0.937590;-0.330512;,
  0.018479;0.943043;-0.332157;,
  0.014190;0.943120;-0.332149;,
  -0.075571;0.940930;-0.330059;,
  -0.226241;0.937046;-0.266006;,
  -0.299513;0.910290;-0.285767;,
  -0.285231;0.850001;-0.442878;,
  -0.214872;0.792555;-0.570689;,
  -0.109151;0.752543;-0.649434;,
  0.003315;0.312695;-0.949848;,
  0.256715;0.338807;-0.905156;,
  0.492236;0.424580;-0.759892;,
  0.664064;0.555190;-0.500783;,
  0.706224;0.689697;-0.159891;,
  0.623056;0.781393;0.035030;,
  0.403249;0.904251;0.140426;,
  0.019116;0.944254;-0.328663;,
  0.013616;0.944352;-0.328656;,
  -0.360211;0.928818;-0.086864;,
  -0.594026;0.803544;0.038076;,
  -0.681449;0.714955;-0.156415;,
  -0.645919;0.579031;-0.497505;,
  -0.480255;0.442277;-0.757460;,
  -0.248739;0.348003;-0.903893;,
  -0.001746;0.060828;-0.998147;,
  0.298707;0.095047;-0.949600;,
  0.585084;0.200315;-0.785844;,
  0.799538;0.361963;-0.479293;,
  0.846135;0.528546;-0.068514;,
  0.726455;0.612984;0.310667;,
  0.482744;0.635188;0.602905;,
  0.163916;0.639242;0.751333;,
  -0.139375;0.642085;0.753858;,
  -0.460557;0.644171;0.610681;,
  -0.710105;0.626125;0.322055;,
  -0.838196;0.542261;-0.058148;,
  -0.798174;0.372830;-0.473198;,
  -0.586587;0.207065;-0.782969;,
  -0.301638;0.098325;-0.948339;,
  -0.004346;-0.028034;-0.999598;,
  0.314370;0.001298;-0.949300;,
  0.624935;0.091157;-0.775337;,
  0.867028;0.232751;-0.440556;,
  0.923775;0.382609;0.015846;,
  0.758866;0.484575;0.435097;,
  0.474872;0.530551;0.702149;,
  0.164978;0.545852;0.821479;,
  -0.145862;0.547259;0.824156;,
  -0.458157;0.534536;0.710186;,
  -0.747781;0.490615;0.447348;,
  -0.920797;0.388996;0.028546;,
  -0.870558;0.237214;-0.431113;,
  -0.631620;0.093452;-0.769625;,
  -0.322535;0.002332;-0.946555;,
  -0.004797;-0.048725;-0.998801;,
  0.318996;-0.033246;-0.947173;,
  0.640946;0.022841;-0.767246;,
  0.901628;0.121755;-0.415022;,
  0.968635;0.238019;0.071363;,
  0.793685;0.325009;0.514231;,
  0.492585;0.369053;0.788137;,
  0.168793;0.386352;0.906775;,
  -0.153739;0.389328;0.908178;,
  -0.478814;0.378014;0.792365;,
  -0.783049;0.339555;0.521092;,
  -0.963422;0.255842;0.079771;,
  -0.902806;0.138402;-0.407168;,
  -0.647070;0.034725;-0.761640;,
  -0.327787;-0.027278;-0.944358;,
  -0.004824;-0.003379;-0.999983;,
  0.319319;0.001069;-0.947647;,
  0.645479;0.013820;-0.763653;,
  0.915901;0.042548;-0.399142;,
  0.990341;0.086122;0.108666;,
  0.811585;0.127734;0.570100;,
  0.501554;0.154700;0.851183;,
  0.170369;0.167266;0.971080;,
  -0.158459;0.168227;0.972929;,
  -0.491009;0.157166;0.856860;,
  -0.804444;0.130228;0.579578;,
  -0.988982;0.086249;0.120316;,
  -0.920535;0.039186;-0.388690;,
  -0.653717;0.008791;-0.756688;,
  -0.328779;-0.002516;-0.944404;,
  -0.004584;0.066549;-0.997773;,
  0.317990;0.057834;-0.946329;,
  0.647207;0.024799;-0.761911;,
  0.921770;-0.028294;-0.386703;,
  0.987292;-0.082018;0.136119;,
  0.794711;-0.113238;0.596331;,
  0.484263;-0.122984;0.866236;,
  0.162688;-0.124447;0.978798;,
  -0.153738;-0.124855;0.980192;,
  -0.475759;-0.124621;0.870703;,
  -0.787787;-0.117335;0.604669;,
  -0.984872;-0.089880;0.148151;,
  -0.926194;-0.039089;-0.375016;,
  -0.655872;0.014486;-0.754733;,
  -0.327352;0.051607;-0.943492;,
  -0.003628;0.064152;-0.997934;,
  0.322616;0.048815;-0.945270;,
  0.653059;0.001043;-0.757307;,
  0.922229;-0.077452;-0.378808;,
  0.977017;-0.160762;0.139976;,
  0.779480;-0.213226;0.589021;,
  0.472560;-0.233515;0.849799;,
  0.157732;-0.239017;0.958119;,
  -0.151394;-0.239511;0.959018;,
  -0.466591;-0.234844;0.852725;,
  -0.774858;-0.214976;0.594458;,
  -0.975656;-0.162285;0.147510;,
  -0.925125;-0.078163;-0.371529;,
  -0.658804;0.001070;-0.752314;,
  -0.329558;0.048999;-0.942863;,
  -0.002347;0.097955;-0.995188;,
  0.323404;0.080170;-0.942859;,
  0.653526;0.025549;-0.756473;,
  0.922664;-0.061272;-0.380707;,
  0.979253;-0.150692;0.135485;,
  0.784229;-0.205336;0.585510;,
  0.476811;-0.225271;0.849649;,
  0.158726;-0.230319;0.960083;,
  -0.154370;-0.231692;0.960463;,
  -0.472379;-0.229095;0.851102;,
  -0.780324;-0.210722;0.588805;,
  -0.977691;-0.156032;0.140622;,
  -0.924471;-0.064797;-0.375705;,
  -0.657350;0.024127;-0.753199;,
  -0.327926;0.079805;-0.941327;,
  0.000000;-0.999865;-0.016407;,
  0.005123;-0.999875;-0.014989;,
  0.009361;-0.999896;-0.010979;,
  0.011980;-0.999915;-0.005070;,
  0.012528;-0.999920;0.001715;,
  0.010909;-0.999907;0.008204;,
  0.007404;-0.999884;0.013274;,
  0.002619;-0.999868;0.016049;,
  -0.002619;-0.999868;0.016049;,
  -0.007404;-0.999884;0.013274;,
  -0.010909;-0.999907;0.008204;,
  -0.012528;-0.999920;0.001715;,
  -0.011980;-0.999915;-0.005070;,
  -0.009361;-0.999896;-0.010979;,
  -0.005123;-0.999875;-0.014989;,
  0.000000;-0.999943;-0.010651;,
  0.003326;-0.999947;-0.009731;,
  0.006077;-0.999956;-0.007127;,
  0.007777;-0.999964;-0.003292;,
  0.008133;-0.999966;0.001113;,
  0.007082;-0.999961;0.005326;,
  0.004807;-0.999951;0.008617;,
  0.001700;-0.999944;0.010419;,
  -0.001700;-0.999944;0.010419;,
  -0.004807;-0.999951;0.008617;,
  -0.007082;-0.999961;0.005326;,
  -0.008133;-0.999966;0.001113;,
  -0.007777;-0.999964;-0.003292;,
  -0.006077;-0.999956;-0.007127;,
  -0.003326;-0.999947;-0.009731;,
  0.000000;-0.999979;-0.006508;,
  0.002032;-0.999980;-0.005945;,
  0.003713;-0.999984;-0.004354;,
  0.004752;-0.999987;-0.002011;,
  0.004969;-0.999987;0.000680;,
  0.004327;-0.999985;0.003254;,
  0.002937;-0.999982;0.005265;,
  0.001039;-0.999979;0.006365;,
  -0.001039;-0.999979;0.006365;,
  -0.002937;-0.999982;0.005265;,
  -0.004327;-0.999985;0.003254;,
  -0.004969;-0.999987;0.000680;,
  -0.004752;-0.999987;-0.002011;,
  -0.003713;-0.999984;-0.004354;,
  -0.002032;-0.999980;-0.005945;,
  0.000000;-0.999995;-0.003101;,
  0.000968;-0.999996;-0.002833;,
  0.001769;-0.999996;-0.002075;,
  0.002264;-0.999997;-0.000958;,
  0.002367;-0.999997;0.000324;,
  0.002061;-0.999997;0.001550;,
  0.001399;-0.999996;0.002508;,
  0.000495;-0.999995;0.003033;,
  -0.000495;-0.999995;0.003033;,
  -0.001399;-0.999996;0.002508;,
  -0.002061;-0.999997;0.001550;,
  -0.002367;-0.999997;0.000324;,
  -0.002264;-0.999997;-0.000958;,
  -0.001769;-0.999996;-0.002075;,
  -0.000968;-0.999996;-0.002833;,
  0.000000;-1.000000;-0.000000;,
  0.167286;0.636956;0.752531;,
  -0.140231;0.642552;0.753301;,
  -0.290615;0.633193;0.717363;,
  0.000000;-0.999803;-0.019836;,
  0.006194;-0.999817;-0.018121;,
  0.011317;-0.999848;-0.013273;,
  0.014484;-0.999876;-0.006130;,
  0.015146;-0.999883;0.002074;,
  0.013189;-0.999864;0.009918;,
  0.008951;-0.999831;0.016048;,
  0.003166;-0.999807;0.019402;,
  -0.003166;-0.999807;0.019402;,
  -0.008951;-0.999831;0.016048;,
  -0.013189;-0.999864;0.009918;,
  -0.015146;-0.999883;0.002074;,
  -0.014484;-0.999876;-0.006130;,
  -0.011317;-0.999848;-0.013273;,
  -0.006194;-0.999817;-0.018121;;
  225;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,9,8;,
  3;0,10,9;,
  3;0,11,10;,
  3;0,12,11;,
  3;0,13,12;,
  3;0,14,13;,
  3;0,15,14;,
  3;0,1,15;,
  4;1,2,17,16;,
  4;2,3,18,17;,
  4;3,4,19,18;,
  4;4,5,20,19;,
  4;5,6,21,20;,
  4;6,7,22,21;,
  4;7,8,23,22;,
  4;8,9,24,23;,
  4;9,10,25,24;,
  4;10,11,26,25;,
  4;11,12,27,26;,
  4;12,13,28,27;,
  4;13,14,29,28;,
  4;14,15,30,29;,
  4;15,1,16,30;,
  4;16,17,32,31;,
  4;17,18,33,32;,
  4;18,19,34,33;,
  4;19,20,35,34;,
  4;20,21,36,35;,
  4;21,22,37,36;,
  4;22,23,38,37;,
  4;23,24,39,38;,
  4;24,25,40,39;,
  4;25,26,41,40;,
  4;26,27,42,41;,
  4;27,28,43,42;,
  4;28,29,44,43;,
  4;29,30,45,44;,
  4;30,16,31,45;,
  4;31,32,47,46;,
  4;32,33,48,47;,
  4;33,34,49,48;,
  4;34,35,50,49;,
  4;35,36,51,50;,
  4;36,37,52,51;,
  4;37,212,53,52;,
  4;212,213,54,53;,
  4;213,214,55,54;,
  4;40,41,56,55;,
  4;41,42,57,56;,
  4;42,43,58,57;,
  4;43,44,59,58;,
  4;44,45,60,59;,
  4;45,31,46,60;,
  4;46,47,62,61;,
  4;47,48,63,62;,
  4;48,49,64,63;,
  4;49,50,65,64;,
  4;50,51,66,65;,
  4;51,52,67,66;,
  4;52,53,68,67;,
  4;53,54,69,68;,
  4;54,55,70,69;,
  4;55,56,71,70;,
  4;56,57,72,71;,
  4;57,58,73,72;,
  4;58,59,74,73;,
  4;59,60,75,74;,
  4;60,46,61,75;,
  4;61,62,77,76;,
  4;62,63,78,77;,
  4;63,64,79,78;,
  4;64,65,80,79;,
  4;65,66,81,80;,
  4;66,67,82,81;,
  4;67,68,83,82;,
  4;68,69,84,83;,
  4;69,70,85,84;,
  4;70,71,86,85;,
  4;71,72,87,86;,
  4;72,73,88,87;,
  4;73,74,89,88;,
  4;74,75,90,89;,
  4;75,61,76,90;,
  4;76,77,92,91;,
  4;77,78,93,92;,
  4;78,79,94,93;,
  4;79,80,95,94;,
  4;80,81,96,95;,
  4;81,82,97,96;,
  4;82,83,98,97;,
  4;83,84,99,98;,
  4;84,85,100,99;,
  4;85,86,101,100;,
  4;86,87,102,101;,
  4;87,88,103,102;,
  4;88,89,104,103;,
  4;89,90,105,104;,
  4;90,76,91,105;,
  4;91,92,107,106;,
  4;92,93,108,107;,
  4;93,94,109,108;,
  4;94,95,110,109;,
  4;95,96,111,110;,
  4;96,97,112,111;,
  4;97,98,113,112;,
  4;98,99,114,113;,
  4;99,100,115,114;,
  4;100,101,116,115;,
  4;101,102,117,116;,
  4;102,103,118,117;,
  4;103,104,119,118;,
  4;104,105,120,119;,
  4;105,91,106,120;,
  4;106,107,122,121;,
  4;107,108,123,122;,
  4;108,109,124,123;,
  4;109,110,125,124;,
  4;110,111,126,125;,
  4;111,112,127,126;,
  4;112,113,128,127;,
  4;113,114,129,128;,
  4;114,115,130,129;,
  4;115,116,131,130;,
  4;116,117,132,131;,
  4;117,118,133,132;,
  4;118,119,134,133;,
  4;119,120,135,134;,
  4;120,106,121,135;,
  4;121,122,137,136;,
  4;122,123,138,137;,
  4;123,124,139,138;,
  4;124,125,140,139;,
  4;125,126,141,140;,
  4;126,127,142,141;,
  4;127,128,143,142;,
  4;128,129,144,143;,
  4;129,130,145,144;,
  4;130,131,146,145;,
  4;131,132,147,146;,
  4;132,133,148,147;,
  4;133,134,149,148;,
  4;134,135,150,149;,
  4;135,121,136,150;,
  4;215,216,152,151;,
  4;216,217,153,152;,
  4;217,218,154,153;,
  4;218,219,155,154;,
  4;219,220,156,155;,
  4;220,221,157,156;,
  4;221,222,158,157;,
  4;222,223,159,158;,
  4;223,224,160,159;,
  4;224,225,161,160;,
  4;225,226,162,161;,
  4;226,227,163,162;,
  4;227,228,164,163;,
  4;228,229,165,164;,
  4;229,215,151,165;,
  4;151,152,167,166;,
  4;152,153,168,167;,
  4;153,154,169,168;,
  4;154,155,170,169;,
  4;155,156,171,170;,
  4;156,157,172,171;,
  4;157,158,173,172;,
  4;158,159,174,173;,
  4;159,160,175,174;,
  4;160,161,176,175;,
  4;161,162,177,176;,
  4;162,163,178,177;,
  4;163,164,179,178;,
  4;164,165,180,179;,
  4;165,151,166,180;,
  4;166,167,182,181;,
  4;167,168,183,182;,
  4;168,169,184,183;,
  4;169,170,185,184;,
  4;170,171,186,185;,
  4;171,172,187,186;,
  4;172,173,188,187;,
  4;173,174,189,188;,
  4;174,175,190,189;,
  4;175,176,191,190;,
  4;176,177,192,191;,
  4;177,178,193,192;,
  4;178,179,194,193;,
  4;179,180,195,194;,
  4;180,166,181,195;,
  4;181,182,197,196;,
  4;182,183,198,197;,
  4;183,184,199,198;,
  4;184,185,200,199;,
  4;185,186,201,200;,
  4;186,187,202,201;,
  4;187,188,203,202;,
  4;188,189,204,203;,
  4;189,190,205,204;,
  4;190,191,206,205;,
  4;191,192,207,206;,
  4;192,193,208,207;,
  4;193,194,209,208;,
  4;194,195,210,209;,
  4;195,181,196,210;,
  3;196,197,211;,
  3;197,198,211;,
  3;198,199,211;,
  3;199,200,211;,
  3;200,201,211;,
  3;201,202,211;,
  3;202,203,211;,
  3;203,204,211;,
  3;204,205,211;,
  3;205,206,211;,
  3;206,207,211;,
  3;207,208,211;,
  3;208,209,211;,
  3;209,210,211;,
  3;210,196,211;;
 }
 MeshTextureCoords {
  254;
  0.033330;0.000000;,
  0.066670;0.066670;,
  0.000000;0.066670;,
  0.100000;0.000000;,
  0.133330;0.066670;,
  0.166670;0.000000;,
  0.200000;0.066670;,
  0.233330;0.000000;,
  0.266670;0.066670;,
  0.300000;0.000000;,
  0.333330;0.066670;,
  0.366670;0.000000;,
  0.400000;0.066670;,
  0.433330;0.000000;,
  0.466670;0.066670;,
  0.500000;0.000000;,
  0.533330;0.066670;,
  0.566670;0.000000;,
  0.600000;0.066670;,
  0.633330;0.000000;,
  0.666670;0.066670;,
  0.700000;0.000000;,
  0.733330;0.066670;,
  0.766670;0.000000;,
  0.800000;0.066670;,
  0.833330;0.000000;,
  0.866670;0.066670;,
  0.900000;0.000000;,
  0.933330;0.066670;,
  0.966670;0.000000;,
  1.000000;0.066670;,
  0.066670;0.133330;,
  0.000000;0.133330;,
  0.133330;0.133330;,
  0.200000;0.133330;,
  0.266670;0.133330;,
  0.333330;0.133330;,
  0.400000;0.133330;,
  0.466670;0.133330;,
  0.533330;0.133330;,
  0.600000;0.133330;,
  0.666670;0.133330;,
  0.733330;0.133330;,
  0.800000;0.133330;,
  0.866670;0.133330;,
  0.933330;0.133330;,
  1.000000;0.133330;,
  0.066670;0.200000;,
  0.000000;0.200000;,
  0.133330;0.200000;,
  0.200000;0.200000;,
  0.266670;0.200000;,
  0.333330;0.200000;,
  0.400000;0.200000;,
  0.466670;0.200000;,
  0.533330;0.200000;,
  0.600000;0.200000;,
  0.666670;0.200000;,
  0.733330;0.200000;,
  0.800000;0.200000;,
  0.866670;0.200000;,
  0.933330;0.200000;,
  1.000000;0.200000;,
  0.066670;0.266670;,
  0.000000;0.266670;,
  0.133330;0.266670;,
  0.200000;0.266670;,
  0.266670;0.266670;,
  0.333330;0.266670;,
  0.400000;0.266670;,
  0.466670;0.266670;,
  0.533330;0.266670;,
  0.600000;0.266670;,
  0.666670;0.266670;,
  0.733330;0.266670;,
  0.800000;0.266670;,
  0.866670;0.266670;,
  0.933330;0.266670;,
  1.000000;0.266670;,
  0.066670;0.333330;,
  0.000000;0.333330;,
  0.133330;0.333330;,
  0.200000;0.333330;,
  0.266670;0.333330;,
  0.333330;0.333330;,
  0.400000;0.333330;,
  0.466670;0.333330;,
  0.533330;0.333330;,
  0.600000;0.333330;,
  0.666670;0.333330;,
  0.733330;0.333330;,
  0.800000;0.333330;,
  0.866670;0.333330;,
  0.933330;0.333330;,
  1.000000;0.333330;,
  0.066670;0.400000;,
  0.000000;0.400000;,
  0.133330;0.400000;,
  0.200000;0.400000;,
  0.266670;0.400000;,
  0.333330;0.400000;,
  0.400000;0.400000;,
  0.466670;0.400000;,
  0.533330;0.400000;,
  0.600000;0.400000;,
  0.666670;0.400000;,
  0.733330;0.400000;,
  0.800000;0.400000;,
  0.866670;0.400000;,
  0.933330;0.400000;,
  1.000000;0.400000;,
  0.066670;0.466670;,
  0.000000;0.466670;,
  0.133330;0.466670;,
  0.200000;0.466670;,
  0.266670;0.466670;,
  0.333330;0.466670;,
  0.400000;0.466670;,
  0.466670;0.466670;,
  0.533330;0.466670;,
  0.600000;0.466670;,
  0.666670;0.466670;,
  0.733330;0.466670;,
  0.800000;0.466670;,
  0.866670;0.466670;,
  0.933330;0.466670;,
  1.000000;0.466670;,
  0.066670;0.533330;,
  0.000000;0.533330;,
  0.133330;0.533330;,
  0.200000;0.533330;,
  0.266670;0.533330;,
  0.333330;0.533330;,
  0.400000;0.533330;,
  0.466670;0.533330;,
  0.533330;0.533330;,
  0.600000;0.533330;,
  0.666670;0.533330;,
  0.733330;0.533330;,
  0.800000;0.533330;,
  0.866670;0.533330;,
  0.933330;0.533330;,
  1.000000;0.533330;,
  0.066670;0.600000;,
  0.000000;0.600000;,
  0.133330;0.600000;,
  0.200000;0.600000;,
  0.266670;0.600000;,
  0.333330;0.600000;,
  0.400000;0.600000;,
  0.466670;0.600000;,
  0.533330;0.600000;,
  0.600000;0.600000;,
  0.666670;0.600000;,
  0.733330;0.600000;,
  0.800000;0.600000;,
  0.866670;0.600000;,
  0.933330;0.600000;,
  1.000000;0.600000;,
  0.066670;0.666670;,
  0.000000;0.666670;,
  0.133330;0.666670;,
  0.200000;0.666670;,
  0.266670;0.666670;,
  0.333330;0.666670;,
  0.400000;0.666670;,
  0.466670;0.666670;,
  0.533330;0.666670;,
  0.600000;0.666670;,
  0.666670;0.666670;,
  0.733330;0.666670;,
  0.800000;0.666670;,
  0.866670;0.666670;,
  0.933330;0.666670;,
  1.000000;0.666670;,
  0.066670;0.733330;,
  0.000000;0.733330;,
  0.133330;0.733330;,
  0.200000;0.733330;,
  0.266670;0.733330;,
  0.333330;0.733330;,
  0.400000;0.733330;,
  0.466670;0.733330;,
  0.533330;0.733330;,
  0.600000;0.733330;,
  0.666670;0.733330;,
  0.733330;0.733330;,
  0.800000;0.733330;,
  0.866670;0.733330;,
  0.933330;0.733330;,
  1.000000;0.733330;,
  0.066670;0.800000;,
  0.000000;0.800000;,
  0.133330;0.800000;,
  0.200000;0.800000;,
  0.266670;0.800000;,
  0.333330;0.800000;,
  0.400000;0.800000;,
  0.466670;0.800000;,
  0.533330;0.800000;,
  0.600000;0.800000;,
  0.666670;0.800000;,
  0.733330;0.800000;,
  0.800000;0.800000;,
  0.866670;0.800000;,
  0.933330;0.800000;,
  1.000000;0.800000;,
  0.066670;0.866670;,
  0.000000;0.866670;,
  0.133330;0.866670;,
  0.200000;0.866670;,
  0.266670;0.866670;,
  0.333330;0.866670;,
  0.400000;0.866670;,
  0.466670;0.866670;,
  0.533330;0.866670;,
  0.600000;0.866670;,
  0.666670;0.866670;,
  0.733330;0.866670;,
  0.800000;0.866670;,
  0.866670;0.866670;,
  0.933330;0.866670;,
  1.000000;0.866670;,
  0.066670;0.933330;,
  0.000000;0.933330;,
  0.133330;0.933330;,
  0.200000;0.933330;,
  0.266670;0.933330;,
  0.333330;0.933330;,
  0.400000;0.933330;,
  0.466670;0.933330;,
  0.533330;0.933330;,
  0.600000;0.933330;,
  0.666670;0.933330;,
  0.733330;0.933330;,
  0.800000;0.933330;,
  0.866670;0.933330;,
  0.933330;0.933330;,
  1.000000;0.933330;,
  0.033330;1.000000;,
  0.100000;1.000000;,
  0.166670;1.000000;,
  0.233330;1.000000;,
  0.300000;1.000000;,
  0.366670;1.000000;,
  0.433330;1.000000;,
  0.500000;1.000000;,
  0.566670;1.000000;,
  0.633330;1.000000;,
  0.700000;1.000000;,
  0.766670;1.000000;,
  0.833330;1.000000;,
  0.900000;1.000000;,
  0.966670;1.000000;;
 }
}
