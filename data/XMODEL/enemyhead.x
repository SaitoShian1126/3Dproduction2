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
 159;
 -0.10909;9.94769;0.00000;,
 1.21702;9.57464;-1.32610;,
 -0.10909;9.57464;-1.87539;,
 -0.10909;9.94769;0.00000;,
 1.76631;9.57464;0.00000;,
 -0.10909;9.94769;0.00000;,
 1.21702;9.57464;1.32610;,
 -0.10909;9.94769;0.00000;,
 -0.10909;9.57464;1.87539;,
 -0.10909;9.94769;0.00000;,
 -1.43519;9.57464;1.32610;,
 -0.10909;9.94769;0.00000;,
 -1.98447;9.57464;0.00000;,
 -0.10909;9.94769;0.00000;,
 -1.43519;9.57464;-1.32610;,
 -0.10909;9.94769;0.00000;,
 -0.10909;9.57464;-1.87539;,
 2.34123;8.51233;-2.45032;,
 -0.10909;8.51233;-3.46527;,
 3.35619;8.51233;0.00000;,
 2.34123;8.51233;2.45032;,
 -0.10909;8.51233;3.46527;,
 -2.55940;8.51233;2.45032;,
 -3.57435;8.51233;0.00000;,
 -2.55940;8.51233;-2.45032;,
 -0.10909;8.51233;-3.46527;,
 3.09241;6.92246;-3.20149;,
 -0.10909;6.92246;-4.52760;,
 4.41851;6.92246;0.00000;,
 3.09241;6.92246;3.20149;,
 -3.31058;6.92246;3.20149;,
 -0.10909;6.92246;4.52760;,
 -4.63668;6.92246;0.00000;,
 -3.31058;6.92246;-3.20149;,
 -0.10909;6.92246;-4.52760;,
 4.79155;5.04704;0.00000;,
 3.35619;5.04704;-3.46527;,
 3.35619;5.04704;3.46527;,
 -5.00972;5.04704;0.00000;,
 -3.57435;5.04704;3.46527;,
 -3.57435;5.04704;-3.46527;,
 -0.10909;5.04704;-4.90064;,
 3.09241;3.17166;-3.20149;,
 -0.10909;3.17166;-4.52760;,
 4.41851;3.17166;0.00000;,
 3.09241;3.17166;3.20149;,
 -0.10909;5.04704;4.90064;,
 -0.10909;3.17166;4.52760;,
 -3.31058;3.17166;3.20149;,
 -4.63668;3.17166;0.00000;,
 -3.31058;3.17166;-3.20149;,
 -0.10909;5.04704;-4.90064;,
 -0.10909;3.17166;-4.52760;,
 3.35619;1.58177;0.00000;,
 2.34123;1.58177;-2.45032;,
 2.34123;1.58177;2.45032;,
 -2.55940;1.58177;2.45032;,
 -0.10909;1.58177;3.46527;,
 -3.57435;1.58177;0.00000;,
 -2.55940;1.58177;-2.45032;,
 -0.10909;1.58177;-3.46527;,
 1.21702;0.51947;-1.32610;,
 -0.10909;0.51947;-1.87539;,
 1.76631;0.51947;0.00000;,
 1.21702;0.51947;1.32610;,
 -0.10909;0.51947;1.87539;,
 -1.43519;0.51947;1.32610;,
 -1.98447;0.51947;0.00000;,
 -1.43519;0.51947;-1.32610;,
 -0.10909;1.58177;-3.46527;,
 -0.10909;0.51947;-1.87539;,
 -0.10909;0.14641;0.00000;,
 -0.10909;0.14641;0.00000;,
 -0.10909;0.14641;0.00000;,
 -0.10909;0.14641;0.00000;,
 -0.10909;0.14641;0.00000;,
 -0.10909;0.14641;0.00000;,
 -0.10909;0.14641;0.00000;,
 -0.10909;0.14641;0.00000;,
 -2.37139;6.92246;-3.59052;,
 -2.35483;5.04704;-3.97042;,
 -2.81544;5.49510;3.69050;,
 -2.77417;6.92246;3.42368;,
 -2.79401;6.92246;3.41546;,
 -2.82840;5.04704;3.77426;,
 -2.82217;5.04704;3.77683;,
 -0.74529;6.92246;-4.26407;,
 -0.75468;5.04704;-4.63322;,
 -0.72022;5.04704;4.64750;,
 -0.71471;6.60305;4.34027;,
 -0.71358;6.92246;4.27720;,
 0.95477;6.92246;-4.08693;,
 0.94908;5.04704;-4.46233;,
 1.52972;6.92246;3.84878;,
 1.57683;5.04704;4.20231;,
 3.00375;6.92246;3.23822;,
 2.97014;7.18126;3.07922;,
 2.18068;6.92246;-3.57915;,
 2.24324;5.04704;-3.92627;,
 3.14614;5.04704;3.55228;,
 3.00375;6.92246;3.23821;,
 -0.10909;1.96972;-3.72449;,
 -2.75450;1.99470;-2.64541;,
 2.48630;1.88882;-2.59539;,
 -0.10909;1.96153;-3.71902;,
 -0.10909;3.08115;4.46712;,
 2.82976;2.61577;2.93885;,
 -1.83835;7.61600;-2.75014;,
 -4.79321;12.39146;-0.03656;,
 -0.17653;8.61202;-1.85366;,
 -4.79321;12.39146;-0.03656;,
 0.44367;9.00915;0.15010;,
 -4.79321;12.39146;-0.03656;,
 -0.34106;8.57477;2.08734;,
 -4.79321;12.39146;-0.03656;,
 -2.07102;7.56333;2.82326;,
 -4.79321;12.39146;-0.03656;,
 -3.73284;6.56731;1.92677;,
 -4.79321;12.39146;-0.03656;,
 -4.35304;6.17018;-0.07698;,
 -4.79321;12.39146;-0.03656;,
 -3.56832;6.60456;-2.01422;,
 -4.79321;12.39146;-0.03656;,
 -1.83835;7.61600;-2.75014;,
 -1.95469;7.58966;0.03656;,
 -1.83835;7.61600;-2.75014;,
 -0.17653;8.61202;-1.85366;,
 0.44367;9.00915;0.15010;,
 -0.34106;8.57477;2.08734;,
 -2.07102;7.56333;2.82326;,
 -3.73284;6.56731;1.92677;,
 -4.35304;6.17018;-0.07698;,
 -3.56832;6.60456;-2.01422;,
 2.05812;7.95126;-2.80228;,
 4.77624;12.78472;0.05239;,
 3.74470;6.96569;-1.94119;,
 4.77624;12.78472;0.05239;,
 4.40173;6.55902;0.04887;,
 4.77624;12.78472;0.05239;,
 3.64435;6.96949;2.00213;,
 4.77624;12.78472;0.05239;,
 1.91621;7.95664;2.77443;,
 4.77624;12.78472;0.05239;,
 0.22963;8.94222;1.91334;,
 4.77624;12.78472;0.05239;,
 -0.42740;9.34888;-0.07671;,
 4.77624;12.78472;0.05239;,
 0.32998;8.93842;-2.02999;,
 4.77624;12.78472;0.05239;,
 2.05812;7.95126;-2.80228;,
 1.98717;7.95395;-0.01392;,
 2.05812;7.95126;-2.80228;,
 3.74470;6.96569;-1.94119;,
 4.40173;6.55902;0.04887;,
 3.64435;6.96949;2.00213;,
 1.91621;7.95664;2.77443;,
 0.22963;8.94222;1.91334;,
 -0.42740;9.34888;-0.07671;,
 0.32998;8.93842;-2.02999;;
 
 114;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 3;13,14,12;,
 3;15,16,14;,
 4;2,1,17,18;,
 4;1,4,19,17;,
 4;4,6,20,19;,
 4;6,8,21,20;,
 4;8,10,22,21;,
 4;10,12,23,22;,
 4;12,14,24,23;,
 4;14,16,25,24;,
 4;18,17,26,27;,
 4;17,19,28,26;,
 4;19,20,29,28;,
 4;21,22,30,31;,
 4;22,23,32,30;,
 4;23,24,33,32;,
 4;24,25,34,33;,
 4;26,28,35,36;,
 4;28,29,37,35;,
 4;30,32,38,39;,
 4;32,33,40,38;,
 4;41,36,42,43;,
 4;36,35,44,42;,
 4;35,37,45,44;,
 4;37,46,47,45;,
 4;46,39,48,47;,
 4;39,38,49,48;,
 4;38,40,50,49;,
 4;40,51,52,50;,
 4;42,44,53,54;,
 4;44,45,55,53;,
 4;47,48,56,57;,
 4;48,49,58,56;,
 4;49,50,59,58;,
 4;60,54,61,62;,
 4;54,53,63,61;,
 4;53,55,64,63;,
 4;55,57,65,64;,
 4;57,56,66,65;,
 4;56,58,67,66;,
 4;58,59,68,67;,
 4;59,69,70,68;,
 3;62,61,71;,
 3;61,63,72;,
 3;63,64,73;,
 3;64,65,74;,
 3;65,66,75;,
 3;66,67,76;,
 3;67,68,77;,
 3;68,70,78;,
 4;79,80,40,33;,
 3;81,82,83;,
 4;81,83,30,39;,
 3;81,39,84;,
 3;81,84,85;,
 4;86,34,51,87;,
 4;86,87,80,79;,
 4;88,46,31,89;,
 4;88,89,81,85;,
 3;89,31,90;,
 4;89,90,82,81;,
 4;91,92,41,27;,
 4;93,31,46,94;,
 3;95,29,96;,
 4;95,96,20,21;,
 3;95,21,31;,
 4;97,26,36,98;,
 4;97,98,92,91;,
 4;99,37,29,100;,
 4;99,100,93,94;,
 4;101,69,59,102;,
 4;101,102,50,52;,
 4;103,54,60,104;,
 4;103,104,43,42;,
 4;105,57,55,106;,
 4;105,106,45,47;,
 3;107,108,109;,
 3;109,110,111;,
 3;111,112,113;,
 3;113,114,115;,
 3;115,116,117;,
 3;117,118,119;,
 3;119,120,121;,
 3;121,122,123;,
 3;124,125,126;,
 3;124,126,127;,
 3;124,127,128;,
 3;124,128,129;,
 3;124,129,130;,
 3;124,130,131;,
 3;124,131,132;,
 3;124,132,125;,
 3;133,134,135;,
 3;135,136,137;,
 3;137,138,139;,
 3;139,140,141;,
 3;141,142,143;,
 3;143,144,145;,
 3;145,146,147;,
 3;147,148,149;,
 3;150,151,152;,
 3;150,152,153;,
 3;150,153,154;,
 3;150,154,155;,
 3;150,155,156;,
 3;150,156,157;,
 3;150,157,158;,
 3;150,158,151;;
 
 MeshMaterialList {
  11;
  114;
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
  9,
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
  9,
  0,
  0,
  9,
  0,
  9,
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
   0.800000;0.024800;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.225600;0.800000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.746400;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.778400;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.012800;0.000000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.787200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.373600;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.496000;0.000000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.800000;0.501600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.618039;0.410980;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  111;
  -0.000001;1.000000;-0.000000;,
  -0.000000;0.924735;-0.380611;,
  0.269132;0.924735;-0.269133;,
  0.380611;0.924735;0.000000;,
  0.269132;0.924735;0.269133;,
  -0.000000;0.924735;0.380611;,
  -0.269133;0.924735;0.269132;,
  -0.380612;0.924735;0.000000;,
  -0.269133;0.924735;-0.269132;,
  -0.000001;0.709234;-0.704973;,
  0.498491;0.709234;-0.498492;,
  0.704973;0.709234;0.000000;,
  0.498490;0.709234;0.498492;,
  0.069164;0.678936;0.730932;,
  -0.498492;0.709235;0.498490;,
  -0.704973;0.709234;0.000000;,
  -0.498492;0.709235;-0.498490;,
  -0.000002;0.384553;-0.923103;,
  0.652733;0.384552;-0.652732;,
  0.923103;0.384552;0.000000;,
  0.652739;0.384550;0.652727;,
  -0.081839;0.346316;0.934541;,
  -0.652733;0.384552;0.652732;,
  -0.923103;0.384552;0.000000;,
  -0.652734;0.384552;-0.652732;,
  -0.000002;-0.000002;-1.000000;,
  0.707108;-0.000003;-0.707106;,
  1.000000;-0.000002;-0.000000;,
  0.707105;-0.000002;0.707108;,
  -0.000002;-0.000002;1.000000;,
  -0.645808;0.039615;0.762471;,
  -1.000000;-0.000002;0.000000;,
  -0.707108;-0.000002;-0.707106;,
  -0.000001;-0.384551;-0.923104;,
  0.652733;-0.384551;-0.652733;,
  0.923104;-0.384551;-0.000000;,
  0.652732;-0.384555;0.652731;,
  -0.000002;-0.384555;0.923102;,
  -0.652734;-0.384550;0.652732;,
  -0.923104;-0.384550;0.000000;,
  -0.652734;-0.384551;-0.652732;,
  -0.000001;-0.709234;-0.704974;,
  0.498491;-0.709234;-0.498492;,
  0.704974;-0.709233;-0.000000;,
  0.498492;-0.709233;0.498492;,
  -0.000000;-0.709233;0.704974;,
  -0.498492;-0.709234;0.498491;,
  -0.704974;-0.709233;0.000000;,
  -0.498492;-0.709233;-0.498491;,
  -0.000000;-0.924736;-0.380610;,
  0.269131;-0.924736;-0.269132;,
  0.380610;-0.924736;-0.000000;,
  0.269131;-0.924736;0.269132;,
  -0.000000;-0.924736;0.380610;,
  -0.269132;-0.924736;0.269131;,
  -0.380611;-0.924735;0.000000;,
  -0.269132;-0.924736;-0.269131;,
  -0.000001;-1.000000;0.000000;,
  -0.376426;0.180741;0.908645;,
  -0.375723;0.180783;0.908928;,
  -0.376382;0.180741;-0.908663;,
  -0.376426;0.180739;0.908646;,
  -0.376177;0.180754;0.908746;,
  -0.375721;0.180776;0.908930;,
  -0.376385;0.180741;-0.908662;,
  -0.376386;0.180741;0.908662;,
  -0.376388;0.180744;0.908661;,
  -0.376389;0.180747;0.908659;,
  0.376381;0.180742;-0.908664;,
  0.376382;0.180744;0.908663;,
  0.325654;0.525292;0.786141;,
  0.376382;0.180741;-0.908664;,
  0.325647;0.525293;0.786143;,
  0.376377;0.180744;0.908665;,
  -0.325636;-0.525287;-0.786152;,
  0.325634;-0.525289;-0.786151;,
  0.325632;-0.525294;0.786149;,
  -0.190252;0.393392;-0.899471;,
  0.342642;0.712784;-0.611993;,
  0.541522;0.840131;0.030548;,
  0.289886;0.700839;0.651759;,
  -0.264862;0.376500;0.887748;,
  -0.797755;0.057109;0.600271;,
  -0.996634;-0.070240;-0.042269;,
  -0.744999;0.069054;-0.663482;,
  0.508832;-0.860766;0.013106;,
  0.508831;-0.860767;0.013107;,
  0.508831;-0.860767;0.013106;,
  0.508831;-0.860767;0.013106;,
  0.508831;-0.860767;0.013107;,
  0.508832;-0.860766;0.013107;,
  0.508833;-0.860766;0.013106;,
  0.508832;-0.860766;0.013105;,
  0.508831;-0.860767;0.013106;,
  0.246346;0.386409;-0.888820;,
  0.787180;0.070365;-0.612696;,
  0.997871;-0.060041;0.025452;,
  0.755002;0.071583;0.651804;,
  0.200839;0.388133;0.899453;,
  -0.339995;0.704177;0.623328;,
  -0.550686;0.834581;-0.014817;,
  -0.307816;0.702958;-0.641170;,
  -0.499968;-0.865962;-0.011888;,
  -0.499968;-0.865962;-0.011887;,
  -0.499968;-0.865963;-0.011888;,
  -0.499969;-0.865962;-0.011888;,
  -0.499968;-0.865962;-0.011887;,
  -0.499968;-0.865963;-0.011887;,
  -0.499968;-0.865963;-0.011888;,
  -0.499968;-0.865962;-0.011889;,
  -0.499969;-0.865962;-0.011888;;
  114;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,1,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,8,16,15;,
  4;8,1,9,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,16,24,23;,
  4;16,9,17,24;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;22,23,31,30;,
  4;23,24,32,31;,
  4;25,26,34,33;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;30,31,39,38;,
  4;31,32,40,39;,
  4;32,25,33,40;,
  4;34,35,43,42;,
  4;35,36,44,43;,
  4;37,38,46,45;,
  4;38,39,47,46;,
  4;39,40,48,47;,
  4;41,42,50,49;,
  4;42,43,51,50;,
  4;43,44,52,51;,
  4;44,45,53,52;,
  4;45,46,54,53;,
  4;46,47,55,54;,
  4;47,48,56,55;,
  4;48,41,49,56;,
  3;49,50,57;,
  3;50,51,57;,
  3;51,52,57;,
  3;52,53,57;,
  3;53,54,57;,
  3;54,55,57;,
  3;55,56,57;,
  3;56,49,57;,
  4;60,60,32,24;,
  3;62,58,61;,
  4;62,61,22,30;,
  3;62,30,59;,
  3;62,59,63;,
  4;64,17,25,64;,
  4;64,64,60,60;,
  4;65,29,21,66;,
  4;65,66,62,63;,
  3;66,21,67;,
  4;66,67,58,62;,
  4;68,68,25,17;,
  4;69,21,29,69;,
  3;72,20,70;,
  4;72,70,12,13;,
  3;72,13,21;,
  4;71,18,26,71;,
  4;71,71,68,68;,
  4;73,28,20,73;,
  4;73,73,69,69;,
  4;74,41,48,74;,
  4;74,74,40,33;,
  4;75,42,41,75;,
  4;75,75,33,34;,
  4;76,45,44,76;,
  4;76,76,36,37;,
  3;77,78,78;,
  3;78,78,79;,
  3;79,80,80;,
  3;80,80,81;,
  3;81,82,82;,
  3;82,82,83;,
  3;83,84,84;,
  3;84,84,77;,
  3;85,86,87;,
  3;85,87,88;,
  3;85,88,89;,
  3;85,89,90;,
  3;85,90,91;,
  3;85,91,92;,
  3;85,92,93;,
  3;85,93,86;,
  3;94,95,95;,
  3;95,95,96;,
  3;96,97,97;,
  3;97,97,98;,
  3;98,99,99;,
  3;99,99,100;,
  3;100,101,101;,
  3;101,101,94;,
  3;102,103,104;,
  3;102,104,105;,
  3;102,105,106;,
  3;102,106,107;,
  3;102,107,108;,
  3;102,108,109;,
  3;102,109,110;,
  3;102,110,103;;
 }
 MeshTextureCoords {
  159;
  0.062500;0.000000;,
  0.125000;0.125000;,
  0.000000;0.125000;,
  0.187500;0.000000;,
  0.250000;0.125000;,
  0.312500;0.000000;,
  0.375000;0.125000;,
  0.437500;0.000000;,
  0.500000;0.125000;,
  0.562500;0.000000;,
  0.625000;0.125000;,
  0.687500;0.000000;,
  0.750000;0.125000;,
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.937500;0.000000;,
  1.000000;0.125000;,
  0.125000;0.250000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.125000;0.375000;,
  0.000000;0.375000;,
  0.250000;0.375000;,
  0.375000;0.375000;,
  0.625000;0.375000;,
  0.500000;0.375000;,
  0.750000;0.375000;,
  0.875000;0.375000;,
  1.000000;0.375000;,
  0.250000;0.500000;,
  0.125000;0.500000;,
  0.375000;0.500000;,
  0.750000;0.500000;,
  0.625000;0.500000;,
  0.875000;0.500000;,
  0.000000;0.500000;,
  0.125000;0.625000;,
  0.000000;0.625000;,
  0.250000;0.625000;,
  0.375000;0.625000;,
  0.500000;0.500000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.750000;0.625000;,
  0.875000;0.625000;,
  1.000000;0.500000;,
  1.000000;0.625000;,
  0.250000;0.750000;,
  0.125000;0.750000;,
  0.375000;0.750000;,
  0.625000;0.750000;,
  0.500000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  0.000000;0.750000;,
  0.125000;0.875000;,
  0.000000;0.875000;,
  0.250000;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.750000;0.875000;,
  0.875000;0.875000;,
  1.000000;0.750000;,
  1.000000;0.875000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;,
  0.911670;0.375000;,
  0.918990;0.500000;,
  0.599520;0.470140;,
  0.604060;0.375000;,
  0.604830;0.375000;,
  0.598090;0.500000;,
  0.597870;0.500000;,
  0.975160;0.375000;,
  0.976710;0.500000;,
  0.522050;0.500000;,
  0.522270;0.396290;,
  0.523600;0.375000;,
  0.041540;0.375000;,
  0.038170;0.500000;,
  0.436010;0.375000;,
  0.439190;0.500000;,
  0.378460;0.375000;,
  0.375000;0.354650;,
  0.089400;0.375000;,
  0.084850;0.500000;,
  0.382580;0.500000;,
  0.378460;0.375000;,
  1.000000;0.719500;,
  0.875000;0.717530;,
  0.125000;0.725860;,
  0.000000;0.720140;,
  0.500000;0.632120;,
  0.375000;0.668710;,
  0.000000;1.000000;,
  0.062500;0.000000;,
  0.125000;1.000000;,
  0.125000;0.000000;,
  0.250000;1.000000;,
  0.187500;0.000000;,
  0.375000;1.000000;,
  0.250000;0.000000;,
  0.500000;1.000000;,
  0.312500;0.000000;,
  0.625000;1.000000;,
  0.375000;0.000000;,
  0.750000;1.000000;,
  0.437500;0.000000;,
  0.875000;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.062500;0.000000;,
  0.125000;1.000000;,
  0.125000;0.000000;,
  0.250000;1.000000;,
  0.187500;0.000000;,
  0.375000;1.000000;,
  0.250000;0.000000;,
  0.500000;1.000000;,
  0.312500;0.000000;,
  0.625000;1.000000;,
  0.375000;0.000000;,
  0.750000;1.000000;,
  0.437500;0.000000;,
  0.875000;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
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
