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
 112;
 0.13070;-1.10121;-0.01553;,
 2.39053;-1.10121;-3.53186;,
 0.13070;-1.10121;-4.19542;,
 3.93288;-1.10121;-1.75193;,
 4.26808;-1.10121;0.57933;,
 3.28966;-1.10121;2.72174;,
 1.30832;-1.10121;3.99506;,
 -1.04693;-1.10121;3.99506;,
 -3.02830;-1.10121;2.72174;,
 -4.00669;-1.10121;0.57933;,
 -3.67149;-1.10121;-1.75193;,
 -2.12914;-1.10121;-3.53186;,
 2.60673;-1.28148;-3.86830;,
 0.13070;-1.28148;-4.59532;,
 4.29666;-1.28148;-1.91803;,
 4.66392;-1.28148;0.63624;,
 3.59191;-1.28148;2.98363;,
 1.42098;-1.28148;4.37878;,
 -1.15959;-1.28148;4.37878;,
 -3.33048;-1.28148;2.98363;,
 -4.40250;-1.28148;0.63624;,
 -4.03524;-1.28148;-1.91803;,
 -2.34534;-1.28148;-3.86830;,
 2.79000;-1.79471;-4.15354;,
 0.13070;-1.79471;-4.93436;,
 4.60502;-1.79471;-2.05883;,
 4.99946;-1.79471;0.68451;,
 3.84809;-1.79471;3.20562;,
 1.51649;-1.79471;4.70406;,
 -1.25510;-1.79471;4.70406;,
 -3.58670;-1.79471;3.20562;,
 -4.73807;-1.79471;0.68451;,
 -4.34363;-1.79471;-2.05883;,
 -2.52864;-1.79471;-4.15354;,
 2.91248;-2.56289;-4.34409;,
 0.13070;-2.56289;-5.16088;,
 4.81108;-2.56289;-2.15295;,
 5.22369;-2.56289;0.71675;,
 4.01930;-2.56289;3.35398;,
 1.58032;-2.56289;4.92140;,
 -1.31893;-2.56289;4.92140;,
 -3.75791;-2.56289;3.35398;,
 -4.96226;-2.56289;0.71675;,
 -4.54968;-2.56289;-2.15295;,
 -2.65109;-2.56289;-4.34409;,
 2.95551;-3.46899;-4.41096;,
 0.13070;-3.46899;-5.24046;,
 4.88343;-3.46899;-2.18600;,
 5.30243;-3.46899;0.72807;,
 4.07941;-3.46899;3.40603;,
 1.60270;-3.46899;4.99776;,
 -1.34134;-3.46899;4.99776;,
 -3.81802;-3.46899;3.40603;,
 -5.04100;-3.46899;0.72807;,
 -4.62204;-3.46899;-2.18600;,
 -2.69409;-3.46899;-4.41096;,
 2.95551;-22.41127;-4.41096;,
 0.13070;-22.41127;-5.24046;,
 4.88343;-22.41127;-2.18600;,
 5.30243;-22.41127;0.72807;,
 4.07941;-22.41127;3.40603;,
 1.60270;-22.41127;4.99776;,
 -1.34134;-22.41127;4.99776;,
 -3.81802;-22.41127;3.40603;,
 -5.04100;-22.41127;0.72807;,
 -4.62204;-22.41127;-2.18600;,
 -2.69409;-22.41127;-4.41096;,
 2.91248;-23.31736;-4.34409;,
 0.13070;-23.31736;-5.16088;,
 4.81108;-23.31736;-2.15295;,
 5.22369;-23.31736;0.71675;,
 4.01930;-23.31736;3.35398;,
 1.58032;-23.31736;4.92140;,
 -1.31893;-23.31736;4.92140;,
 -3.75791;-23.31736;3.35398;,
 -4.96226;-23.31736;0.71675;,
 -4.54968;-23.31736;-2.15295;,
 -2.65109;-23.31736;-4.34409;,
 2.79000;-24.08554;-4.15354;,
 0.13070;-24.08554;-4.93436;,
 4.60502;-24.08554;-2.05883;,
 4.99946;-24.08554;0.68451;,
 3.84809;-24.08554;3.20562;,
 1.51649;-24.08554;4.70406;,
 -1.25510;-24.08554;4.70406;,
 -3.58670;-24.08554;3.20562;,
 -4.73807;-24.08554;0.68451;,
 -4.34363;-24.08554;-2.05883;,
 -2.52864;-24.08554;-4.15354;,
 2.60673;-24.59878;-3.86830;,
 0.13070;-24.59878;-4.59532;,
 4.29666;-24.59878;-1.91803;,
 4.66392;-24.59878;0.63624;,
 3.59191;-24.59878;2.98363;,
 1.42098;-24.59878;4.37878;,
 -1.15959;-24.59878;4.37878;,
 -3.33048;-24.59878;2.98363;,
 -4.40250;-24.59878;0.63624;,
 -4.03524;-24.59878;-1.91803;,
 -2.34534;-24.59878;-3.86830;,
 2.39053;-24.77901;-3.53186;,
 0.13070;-24.77901;-4.19542;,
 3.93288;-24.77901;-1.75193;,
 4.26808;-24.77901;0.57933;,
 3.28966;-24.77901;2.72174;,
 1.30832;-24.77901;3.99506;,
 -1.04693;-24.77901;3.99506;,
 -3.02830;-24.77901;2.72174;,
 -4.00669;-24.77901;0.57933;,
 -3.67149;-24.77901;-1.75193;,
 -2.12914;-24.77901;-3.53186;,
 0.13070;-24.77901;-0.01553;;
 
 121;
 3;0,1,2;,
 3;0,3,1;,
 3;0,4,3;,
 3;0,5,4;,
 3;0,6,5;,
 3;0,7,6;,
 3;0,8,7;,
 3;0,9,8;,
 3;0,10,9;,
 3;0,11,10;,
 3;0,2,11;,
 4;2,1,12,13;,
 4;1,3,14,12;,
 4;3,4,15,14;,
 4;4,5,16,15;,
 4;5,6,17,16;,
 4;6,7,18,17;,
 4;7,8,19,18;,
 4;8,9,20,19;,
 4;9,10,21,20;,
 4;10,11,22,21;,
 4;11,2,13,22;,
 4;13,12,23,24;,
 4;12,14,25,23;,
 4;14,15,26,25;,
 4;15,16,27,26;,
 4;16,17,28,27;,
 4;17,18,29,28;,
 4;18,19,30,29;,
 4;19,20,31,30;,
 4;20,21,32,31;,
 4;21,22,33,32;,
 4;22,13,24,33;,
 4;24,23,34,35;,
 4;23,25,36,34;,
 4;25,26,37,36;,
 4;26,27,38,37;,
 4;27,28,39,38;,
 4;28,29,40,39;,
 4;29,30,41,40;,
 4;30,31,42,41;,
 4;31,32,43,42;,
 4;32,33,44,43;,
 4;33,24,35,44;,
 4;35,34,45,46;,
 4;34,36,47,45;,
 4;36,37,48,47;,
 4;37,38,49,48;,
 4;38,39,50,49;,
 4;39,40,51,50;,
 4;40,41,52,51;,
 4;41,42,53,52;,
 4;42,43,54,53;,
 4;43,44,55,54;,
 4;44,35,46,55;,
 4;46,45,56,57;,
 4;45,47,58,56;,
 4;47,48,59,58;,
 4;48,49,60,59;,
 4;49,50,61,60;,
 4;50,51,62,61;,
 4;51,52,63,62;,
 4;52,53,64,63;,
 4;53,54,65,64;,
 4;54,55,66,65;,
 4;55,46,57,66;,
 4;57,56,67,68;,
 4;56,58,69,67;,
 4;58,59,70,69;,
 4;59,60,71,70;,
 4;60,61,72,71;,
 4;61,62,73,72;,
 4;62,63,74,73;,
 4;63,64,75,74;,
 4;64,65,76,75;,
 4;65,66,77,76;,
 4;66,57,68,77;,
 4;68,67,78,79;,
 4;67,69,80,78;,
 4;69,70,81,80;,
 4;70,71,82,81;,
 4;71,72,83,82;,
 4;72,73,84,83;,
 4;73,74,85,84;,
 4;74,75,86,85;,
 4;75,76,87,86;,
 4;76,77,88,87;,
 4;77,68,79,88;,
 4;79,78,89,90;,
 4;78,80,91,89;,
 4;80,81,92,91;,
 4;81,82,93,92;,
 4;82,83,94,93;,
 4;83,84,95,94;,
 4;84,85,96,95;,
 4;85,86,97,96;,
 4;86,87,98,97;,
 4;87,88,99,98;,
 4;88,79,90,99;,
 4;90,89,100,101;,
 4;89,91,102,100;,
 4;91,92,103,102;,
 4;92,93,104,103;,
 4;93,94,105,104;,
 4;94,95,106,105;,
 4;95,96,107,106;,
 4;96,97,108,107;,
 4;97,98,109,108;,
 4;98,99,110,109;,
 4;99,90,101,110;,
 3;101,100,111;,
 3;100,102,111;,
 3;102,103,111;,
 3;103,104,111;,
 3;104,105,111;,
 3;105,106,111;,
 3;106,107,111;,
 3;107,108,111;,
 3;108,109,111;,
 3;109,110,111;,
 3;110,101,111;;
 
 MeshMaterialList {
  6;
  121;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
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
  112;
  0.000000;1.000000;0.000000;,
  -0.000000;0.977829;-0.209405;,
  0.113214;0.977829;-0.176165;,
  0.190482;0.977829;-0.086992;,
  0.207272;0.977829;0.029801;,
  0.158256;0.977829;0.137130;,
  0.058996;0.977829;0.200921;,
  -0.058998;0.977829;0.200925;,
  -0.158267;0.977826;0.137138;,
  -0.207289;0.977826;0.029803;,
  -0.190492;0.977827;-0.086995;,
  -0.113216;0.977828;-0.176166;,
  0.000001;0.763506;-0.645801;,
  0.349155;0.763495;-0.543292;,
  0.587466;0.763483;-0.268288;,
  0.639253;0.763484;0.091910;,
  0.488081;0.763486;0.422926;,
  0.181949;0.763490;0.619659;,
  -0.181950;0.763490;0.619659;,
  -0.488083;0.763484;0.422926;,
  -0.639252;0.763485;0.091910;,
  -0.587461;0.763488;-0.268282;,
  -0.349153;0.763500;-0.543286;,
  0.000001;0.422269;-0.906471;,
  0.490080;0.422260;-0.762573;,
  0.824567;0.422244;-0.376564;,
  0.897256;0.422244;0.129005;,
  0.685071;0.422250;0.593619;,
  0.255385;0.422250;0.869761;,
  -0.255385;0.422253;0.869759;,
  -0.685069;0.422258;0.593615;,
  -0.897251;0.422255;0.129005;,
  -0.824564;0.422254;-0.376558;,
  -0.490080;0.422265;-0.762571;,
  -0.000000;0.186202;-0.982512;,
  0.531189;0.186208;-0.826538;,
  0.893723;0.186213;-0.408147;,
  0.972509;0.186215;0.139825;,
  0.742530;0.186213;0.643408;,
  0.276805;0.186217;0.942710;,
  -0.276805;0.186220;0.942709;,
  -0.742534;0.186212;0.643404;,
  -0.972510;0.186206;0.139826;,
  -0.893727;0.186202;-0.408144;,
  -0.531190;0.186199;-0.826539;,
  -0.000001;0.043770;-0.999042;,
  0.540131;0.043770;-0.840442;,
  0.908760;0.043773;-0.415016;,
  0.988873;0.043772;0.142179;,
  0.755026;0.043767;0.654233;,
  0.281466;0.043779;0.958572;,
  -0.281468;0.043782;0.958571;,
  -0.755030;0.043770;0.654227;,
  -0.988873;0.043772;0.142179;,
  -0.908761;0.043769;-0.415014;,
  -0.540129;0.043766;-0.840443;,
  -0.000001;-0.043770;-0.999042;,
  0.540131;-0.043771;-0.840442;,
  0.908760;-0.043773;-0.415016;,
  0.988873;-0.043772;0.142179;,
  0.755026;-0.043767;0.654233;,
  0.281466;-0.043779;0.958572;,
  -0.281468;-0.043781;0.958571;,
  -0.755030;-0.043770;0.654227;,
  -0.988873;-0.043772;0.142179;,
  -0.908761;-0.043769;-0.415014;,
  -0.540129;-0.043766;-0.840443;,
  -0.000000;-0.186202;-0.982511;,
  0.531189;-0.186209;-0.826538;,
  0.893723;-0.186213;-0.408147;,
  0.972509;-0.186215;0.139825;,
  0.742530;-0.186213;0.643408;,
  0.276805;-0.186218;0.942710;,
  -0.276805;-0.186220;0.942709;,
  -0.742534;-0.186211;0.643404;,
  -0.972510;-0.186205;0.139826;,
  -0.893727;-0.186202;-0.408144;,
  -0.531190;-0.186199;-0.826539;,
  0.000001;-0.422268;-0.906471;,
  0.490080;-0.422260;-0.762573;,
  0.824567;-0.422244;-0.376564;,
  0.897256;-0.422244;0.129005;,
  0.685071;-0.422249;0.593619;,
  0.255385;-0.422250;0.869761;,
  -0.255385;-0.422253;0.869759;,
  -0.685069;-0.422257;0.593616;,
  -0.897251;-0.422254;0.129005;,
  -0.824564;-0.422254;-0.376558;,
  -0.490080;-0.422265;-0.762571;,
  0.000001;-0.763527;-0.645776;,
  0.349141;-0.763517;-0.543271;,
  0.587442;-0.763504;-0.268277;,
  0.639228;-0.763505;0.091906;,
  0.488062;-0.763507;0.422910;,
  0.181942;-0.763512;0.619635;,
  -0.181943;-0.763511;0.619635;,
  -0.488064;-0.763506;0.422909;,
  -0.639227;-0.763507;0.091906;,
  -0.587438;-0.763510;-0.268271;,
  -0.349139;-0.763522;-0.543265;,
  0.000000;-0.977836;-0.209374;,
  0.113196;-0.977835;-0.176138;,
  0.190453;-0.977836;-0.086979;,
  0.207240;-0.977836;0.029796;,
  0.158231;-0.977836;0.137110;,
  0.058987;-0.977836;0.200891;,
  -0.058989;-0.977835;0.200894;,
  -0.158243;-0.977833;0.137117;,
  -0.207257;-0.977833;0.029799;,
  -0.190463;-0.977833;-0.086981;,
  -0.113199;-0.977835;-0.176139;,
  0.000000;-1.000000;-0.000000;;
  121;
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
  3;0,1,11;,
  4;1,2,13,12;,
  4;2,3,14,13;,
  4;3,4,15,14;,
  4;4,5,16,15;,
  4;5,6,17,16;,
  4;6,7,18,17;,
  4;7,8,19,18;,
  4;8,9,20,19;,
  4;9,10,21,20;,
  4;10,11,22,21;,
  4;11,1,12,22;,
  4;12,13,24,23;,
  4;13,14,25,24;,
  4;14,15,26,25;,
  4;15,16,27,26;,
  4;16,17,28,27;,
  4;17,18,29,28;,
  4;18,19,30,29;,
  4;19,20,31,30;,
  4;20,21,32,31;,
  4;21,22,33,32;,
  4;22,12,23,33;,
  4;23,24,35,34;,
  4;24,25,36,35;,
  4;25,26,37,36;,
  4;26,27,38,37;,
  4;27,28,39,38;,
  4;28,29,40,39;,
  4;29,30,41,40;,
  4;30,31,42,41;,
  4;31,32,43,42;,
  4;32,33,44,43;,
  4;33,23,34,44;,
  4;34,35,46,45;,
  4;35,36,47,46;,
  4;36,37,48,47;,
  4;37,38,49,48;,
  4;38,39,50,49;,
  4;39,40,51,50;,
  4;40,41,52,51;,
  4;41,42,53,52;,
  4;42,43,54,53;,
  4;43,44,55,54;,
  4;44,34,45,55;,
  4;45,46,57,56;,
  4;46,47,58,57;,
  4;47,48,59,58;,
  4;48,49,60,59;,
  4;49,50,61,60;,
  4;50,51,62,61;,
  4;51,52,63,62;,
  4;52,53,64,63;,
  4;53,54,65,64;,
  4;54,55,66,65;,
  4;55,45,56,66;,
  4;56,57,68,67;,
  4;57,58,69,68;,
  4;58,59,70,69;,
  4;59,60,71,70;,
  4;60,61,72,71;,
  4;61,62,73,72;,
  4;62,63,74,73;,
  4;63,64,75,74;,
  4;64,65,76,75;,
  4;65,66,77,76;,
  4;66,56,67,77;,
  4;67,68,79,78;,
  4;68,69,80,79;,
  4;69,70,81,80;,
  4;70,71,82,81;,
  4;71,72,83,82;,
  4;72,73,84,83;,
  4;73,74,85,84;,
  4;74,75,86,85;,
  4;75,76,87,86;,
  4;76,77,88,87;,
  4;77,67,78,88;,
  4;78,79,90,89;,
  4;79,80,91,90;,
  4;80,81,92,91;,
  4;81,82,93,92;,
  4;82,83,94,93;,
  4;83,84,95,94;,
  4;84,85,96,95;,
  4;85,86,97,96;,
  4;86,87,98,97;,
  4;87,88,99,98;,
  4;88,78,89,99;,
  4;89,90,101,100;,
  4;90,91,102,101;,
  4;91,92,103,102;,
  4;92,93,104,103;,
  4;93,94,105,104;,
  4;94,95,106,105;,
  4;95,96,107,106;,
  4;96,97,108,107;,
  4;97,98,109,108;,
  4;98,99,110,109;,
  4;99,89,100,110;,
  3;100,101,111;,
  3;101,102,111;,
  3;102,103,111;,
  3;103,104,111;,
  3;104,105,111;,
  3;105,106,111;,
  3;106,107,111;,
  3;107,108,111;,
  3;108,109,111;,
  3;109,110,111;,
  3;110,100,111;;
 }
 MeshTextureCoords {
  112;
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;;
 }
}