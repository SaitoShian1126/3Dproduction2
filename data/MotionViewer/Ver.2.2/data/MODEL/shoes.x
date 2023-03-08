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
 196;
 1.01470;-2.26595;-3.27978;,
 0.86934;-0.85665;-1.71869;,
 0.95251;-0.85665;-1.69238;,
 1.11178;-2.26595;-3.24534;,
 1.02302;-0.85665;-1.61746;,
 1.19408;-2.26595;-3.14727;,
 1.07014;-0.85665;-1.50534;,
 1.24907;-2.26595;-3.00050;,
 1.08668;-0.85665;-1.37309;,
 1.26838;-2.26595;-2.82736;,
 0.86934;-0.30618;0.75076;,
 0.86934;-2.26595;0.84780;,
 0.95251;-2.26595;0.82149;,
 0.95251;-0.30618;0.72445;,
 1.02302;-2.26595;0.74657;,
 1.02302;-0.30618;0.64954;,
 1.07014;-2.26595;0.63445;,
 1.07014;-0.30618;0.53741;,
 1.08668;-2.26595;0.50220;,
 1.08668;-0.30618;0.40516;,
 -0.86934;-0.85665;-1.71869;,
 -1.01470;-2.26595;-3.27978;,
 -1.11178;-2.26595;-3.24534;,
 -0.95251;-0.85665;-1.69238;,
 -1.19408;-2.26595;-3.14727;,
 -1.02302;-0.85665;-1.61746;,
 -1.24907;-2.26595;-3.00050;,
 -1.07014;-0.85665;-1.50534;,
 -1.26838;-2.26595;-2.82736;,
 -1.08668;-0.85665;-1.37309;,
 -0.86934;-2.26595;0.84780;,
 -0.86934;-0.30618;0.75076;,
 -0.95251;-0.30618;0.72445;,
 -0.95251;-2.26595;0.82149;,
 -1.02302;-0.30618;0.64954;,
 -1.02302;-2.26595;0.74657;,
 -1.07014;-0.30618;0.53741;,
 -1.07014;-2.26595;0.63445;,
 -1.08668;-0.30618;0.40516;,
 -1.08668;-2.26595;0.50220;,
 0.86934;-0.61167;-1.37309;,
 0.95251;-0.63032;-1.37309;,
 0.86934;-0.63032;-1.50534;,
 1.02302;-0.68343;-1.37309;,
 0.97801;-0.68343;-1.54589;,
 0.86934;-0.68343;-1.61746;,
 1.07014;-0.76290;-1.37309;,
 1.04323;-0.76290;-1.53273;,
 0.96974;-0.76290;-1.64960;,
 0.86934;-0.76290;-1.69238;,
 -0.86934;-0.63032;-1.50534;,
 -0.95251;-0.63032;-1.37309;,
 -0.86934;-0.61167;-1.37309;,
 -0.97801;-0.68343;-1.54589;,
 -1.02302;-0.68343;-1.37309;,
 -0.86934;-0.68343;-1.61746;,
 -1.04323;-0.76290;-1.53273;,
 -1.07014;-0.76290;-1.37309;,
 -0.96974;-0.76290;-1.64960;,
 -0.86934;-0.76290;-1.69238;,
 1.01470;-2.49228;-3.00050;,
 1.11178;-2.49228;-2.82736;,
 1.01470;-2.51093;-2.82736;,
 1.14154;-2.43917;-3.05357;,
 1.19408;-2.43917;-2.82736;,
 1.01470;-2.43917;-3.14727;,
 1.21767;-2.35970;-3.03635;,
 1.24907;-2.35970;-2.82736;,
 1.13189;-2.35970;-3.18934;,
 1.01470;-2.35970;-3.24534;,
 0.86934;-0.07985;0.53741;,
 0.95251;-0.07985;0.40516;,
 0.86934;-0.06120;0.40516;,
 0.97801;-0.13295;0.57796;,
 1.02302;-0.13295;0.40516;,
 0.86934;-0.13295;0.64954;,
 1.04323;-0.21243;0.56480;,
 1.07014;-0.21243;0.40516;,
 0.96974;-0.21243;0.68167;,
 0.86934;-0.21243;0.72445;,
 -1.01470;-2.51093;-2.82736;,
 -1.11178;-2.49228;-2.82736;,
 -1.01470;-2.49228;-3.00050;,
 -1.19408;-2.43917;-2.82736;,
 -1.14154;-2.43917;-3.05357;,
 -1.01470;-2.43917;-3.14727;,
 -1.24907;-2.35970;-2.82736;,
 -1.21767;-2.35970;-3.03635;,
 -1.13189;-2.35970;-3.18934;,
 -1.01470;-2.35970;-3.24534;,
 0.86934;-2.51093;0.50220;,
 0.95251;-2.49228;0.50220;,
 0.86934;-2.49228;0.63445;,
 1.02302;-2.43917;0.50220;,
 0.97801;-2.43917;0.67500;,
 0.86934;-2.43917;0.74657;,
 1.07014;-2.35970;0.50220;,
 1.04323;-2.35970;0.66184;,
 0.96974;-2.35970;0.77871;,
 0.86934;-2.35970;0.82149;,
 -0.86934;-0.06120;0.40516;,
 -0.95251;-0.07985;0.40516;,
 -0.86934;-0.07985;0.53741;,
 -1.02302;-0.13295;0.40516;,
 -0.97801;-0.13295;0.57796;,
 -0.86934;-0.13295;0.64954;,
 -1.07014;-0.21243;0.40516;,
 -1.04323;-0.21243;0.56480;,
 -0.96974;-0.21243;0.68167;,
 -0.86934;-0.21243;0.72445;,
 -0.86934;-2.49228;0.63445;,
 -0.95251;-2.49228;0.50220;,
 -0.86934;-2.51093;0.50220;,
 -0.97801;-2.43917;0.67500;,
 -1.02302;-2.43917;0.50220;,
 -0.86934;-2.43917;0.74657;,
 -1.04323;-2.35970;0.66184;,
 -1.07014;-2.35970;0.50220;,
 -0.96974;-2.35970;0.77871;,
 -0.86934;-2.35970;0.82149;,
 1.08668;-2.26595;-0.59707;,
 1.26838;-2.26595;-2.82736;,
 1.08668;-0.85665;-1.37309;,
 1.08668;-0.30618;-0.59707;,
 1.08668;-2.26595;0.50220;,
 -1.08668;-0.30618;-0.59707;,
 -1.08668;-0.85665;-1.37309;,
 -1.26838;-2.26595;-2.82736;,
 -1.08668;-2.26595;-0.59707;,
 -1.08668;-0.30618;0.40516;,
 0.86934;-0.06120;-0.59707;,
 0.95251;-0.07985;-0.59707;,
 1.02302;-0.13295;-0.59707;,
 1.07014;-0.21243;-0.59707;,
 1.08668;-0.30618;-0.59707;,
 0.86934;-2.51093;-0.59707;,
 0.95251;-2.49228;-0.59707;,
 1.02302;-2.43917;-0.59707;,
 1.07014;-2.35970;-0.59707;,
 1.08668;-2.26595;-0.59707;,
 -0.86934;-0.06120;-0.59707;,
 -0.95251;-0.07985;-0.59707;,
 -1.02302;-0.13295;-0.59707;,
 -1.07014;-0.21243;-0.59707;,
 -1.08668;-0.30618;-0.59707;,
 -0.86934;-2.51093;-0.59707;,
 -0.95251;-2.49228;-0.59707;,
 -1.02302;-2.43917;-0.59707;,
 -1.07014;-2.35970;-0.59707;,
 -1.08668;-2.26595;-0.59707;,
 0.00931;-0.85665;-2.31569;,
 0.86934;-0.85665;-1.71869;,
 1.01470;-2.26595;-3.27978;,
 0.00931;-2.26595;-4.06315;,
 -1.01470;-2.26595;-3.27978;,
 0.00931;-2.26595;1.24443;,
 0.86934;-2.26595;0.84780;,
 0.86934;-0.30618;0.75076;,
 0.00931;-0.30618;1.11740;,
 -0.86934;-0.30618;0.75076;,
 0.00931;-0.61167;-1.86326;,
 0.00931;-0.63032;-2.03640;,
 0.00931;-0.68343;-2.18317;,
 0.00931;-0.76290;-2.28125;,
 0.00931;-0.85665;-2.31569;,
 0.00931;-2.49228;-3.78386;,
 0.00931;-2.51093;-2.82736;,
 0.00931;-2.43917;-3.93064;,
 0.00931;-2.35970;-4.02871;,
 0.00931;-2.26595;-4.06315;,
 0.00931;-0.07985;0.83811;,
 0.00931;-0.06120;0.66498;,
 0.00931;-0.13295;0.98489;,
 0.00931;-0.21243;1.08296;,
 0.00931;-0.30618;1.11740;,
 0.00931;-2.51093;0.59164;,
 0.00931;-2.49228;0.76477;,
 0.00931;-2.43917;1.11192;,
 0.00931;-2.35970;1.20999;,
 0.00931;-2.26595;1.24443;,
 0.00931;-0.61167;-1.86326;,
 -0.86934;-0.61167;-1.37309;,
 -0.86934;-0.06120;-0.59707;,
 0.00797;-0.06120;-0.59707;,
 0.86934;-0.06120;-0.59707;,
 0.86934;-0.61167;-1.37309;,
 0.00931;-0.06120;0.66498;,
 0.86934;-0.06120;0.40516;,
 0.00931;-2.51093;0.59164;,
 -0.86934;-2.51093;0.50220;,
 -0.86934;-2.51093;-0.59707;,
 0.00797;-2.51093;-0.59707;,
 0.86934;-2.51093;-0.59707;,
 0.86934;-2.51093;0.50220;,
 0.00931;-2.51093;-2.82736;,
 1.01470;-2.51093;-2.82736;;
 
 224;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;5,4,6,7;,
 4;7,6,8,9;,
 4;10,11,12,13;,
 4;13,12,14,15;,
 4;15,14,16,17;,
 4;17,16,18,19;,
 4;20,21,22,23;,
 4;23,22,24,25;,
 4;25,24,26,27;,
 4;27,26,28,29;,
 4;30,31,32,33;,
 4;33,32,34,35;,
 4;35,34,36,37;,
 4;37,36,38,39;,
 3;40,41,42;,
 3;41,43,44;,
 3;44,42,41;,
 3;42,44,45;,
 3;43,46,47;,
 3;47,44,43;,
 3;44,47,48;,
 3;48,45,44;,
 3;45,48,49;,
 3;46,8,6;,
 3;6,47,46;,
 3;47,6,4;,
 3;4,48,47;,
 3;48,4,2;,
 3;2,49,48;,
 3;49,2,1;,
 3;50,51,52;,
 3;53,54,51;,
 3;51,50,53;,
 3;55,53,50;,
 3;56,57,54;,
 3;54,53,56;,
 3;58,56,53;,
 3;53,55,58;,
 3;59,58,55;,
 3;27,29,57;,
 3;57,56,27;,
 3;25,27,56;,
 3;56,58,25;,
 3;23,25,58;,
 3;58,59,23;,
 3;20,23,59;,
 3;60,61,62;,
 3;63,64,61;,
 3;61,60,63;,
 3;65,63,60;,
 3;66,67,64;,
 3;64,63,66;,
 3;68,66,63;,
 3;63,65,68;,
 3;69,68,65;,
 3;7,9,67;,
 3;67,66,7;,
 3;5,7,66;,
 3;66,68,5;,
 3;3,5,68;,
 3;68,69,3;,
 3;0,3,69;,
 3;70,71,72;,
 3;73,74,71;,
 3;71,70,73;,
 3;75,73,70;,
 3;76,77,74;,
 3;74,73,76;,
 3;78,76,73;,
 3;73,75,78;,
 3;79,78,75;,
 3;17,19,77;,
 3;77,76,17;,
 3;15,17,76;,
 3;76,78,15;,
 3;13,15,78;,
 3;78,79,13;,
 3;10,13,79;,
 3;80,81,82;,
 3;81,83,84;,
 3;84,82,81;,
 3;82,84,85;,
 3;83,86,87;,
 3;87,84,83;,
 3;84,87,88;,
 3;88,85,84;,
 3;85,88,89;,
 3;86,28,26;,
 3;26,87,86;,
 3;87,26,24;,
 3;24,88,87;,
 3;88,24,22;,
 3;22,89,88;,
 3;89,22,21;,
 3;90,91,92;,
 3;91,93,94;,
 3;94,92,91;,
 3;92,94,95;,
 3;93,96,97;,
 3;97,94,93;,
 3;94,97,98;,
 3;98,95,94;,
 3;95,98,99;,
 3;96,18,16;,
 3;16,97,96;,
 3;97,16,14;,
 3;14,98,97;,
 3;98,14,12;,
 3;12,99,98;,
 3;99,12,11;,
 3;100,101,102;,
 3;101,103,104;,
 3;104,102,101;,
 3;102,104,105;,
 3;103,106,107;,
 3;107,104,103;,
 3;104,107,108;,
 3;108,105,104;,
 3;105,108,109;,
 3;106,38,36;,
 3;36,107,106;,
 3;107,36,34;,
 3;34,108,107;,
 3;108,34,32;,
 3;32,109,108;,
 3;109,32,31;,
 3;110,111,112;,
 3;113,114,111;,
 3;111,110,113;,
 3;115,113,110;,
 3;116,117,114;,
 3;114,113,116;,
 3;118,116,113;,
 3;113,115,118;,
 3;119,118,115;,
 3;37,39,117;,
 3;117,116,37;,
 3;35,37,116;,
 3;116,118,35;,
 3;33,35,118;,
 3;118,119,33;,
 3;30,33,119;,
 4;120,121,122,123;,
 4;120,123,19,124;,
 4;125,126,127,128;,
 4;125,128,39,129;,
 4;130,72,71,131;,
 4;130,131,41,40;,
 4;131,71,74,132;,
 4;131,132,43,41;,
 4;132,74,77,133;,
 4;132,133,46,43;,
 4;133,77,19,134;,
 4;133,134,8,46;,
 4;135,62,61,136;,
 4;135,136,91,90;,
 4;136,61,64,137;,
 4;136,137,93,91;,
 4;137,64,67,138;,
 4;137,138,96,93;,
 4;138,67,9,139;,
 4;138,139,18,96;,
 4;140,52,51,141;,
 4;140,141,101,100;,
 4;141,51,54,142;,
 4;141,142,103,101;,
 4;142,54,57,143;,
 4;142,143,106,103;,
 4;143,57,29,144;,
 4;143,144,38,106;,
 4;145,112,111,146;,
 4;145,146,81,80;,
 4;146,111,114,147;,
 4;146,147,83,81;,
 4;147,114,117,148;,
 4;147,148,86,83;,
 4;148,117,39,149;,
 4;148,149,28,86;,
 4;150,151,152,153;,
 4;150,153,154,20;,
 4;155,156,157,158;,
 4;155,158,159,30;,
 4;160,40,42,161;,
 4;160,161,50,52;,
 4;161,42,45,162;,
 4;161,162,55,50;,
 4;162,45,49,163;,
 4;162,163,59,55;,
 4;163,49,1,164;,
 4;163,164,20,59;,
 4;165,60,62,166;,
 4;165,166,80,82;,
 4;167,65,60,165;,
 4;167,165,82,85;,
 4;168,69,65,167;,
 4;168,167,85,89;,
 4;169,0,69,168;,
 4;169,168,89,21;,
 4;170,70,72,171;,
 4;170,171,100,102;,
 4;172,75,70,170;,
 4;172,170,102,105;,
 4;173,79,75,172;,
 4;173,172,105,109;,
 4;174,10,79,173;,
 4;174,173,109,31;,
 4;175,90,92,176;,
 4;175,176,110,112;,
 4;176,92,95,177;,
 4;176,177,115,110;,
 4;177,95,99,178;,
 4;177,178,119,115;,
 4;178,99,11,179;,
 4;178,179,30,119;,
 4;180,181,182,183;,
 4;180,183,184,185;,
 4;183,182,100,186;,
 4;183,186,187,184;,
 4;188,189,190,191;,
 4;188,191,192,193;,
 4;191,190,80,194;,
 4;191,194,195,192;;
 
 MeshMaterialList {
  10;
  224;
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9,
  9;;
  Material {
   0.800000;0.024800;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.702745;0.404706;1.000000;;
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
   0.338824;0.338824;0.338824;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  166;
  -0.119500;0.990679;0.065377;,
  0.119710;0.990654;0.065375;,
  -0.148156;0.929405;-0.338019;,
  0.149100;0.929287;-0.337928;,
  -0.383140;0.510315;-0.769924;,
  0.387231;0.509547;-0.768384;,
  -0.318696;0.721262;-0.614991;,
  0.322218;0.720435;-0.614125;,
  -0.100305;-0.994196;-0.038906;,
  0.100340;-0.994192;-0.038906;,
  -0.113551;-0.991375;0.065438;,
  0.113632;-0.991365;0.065437;,
  -0.350488;-0.112193;0.929823;,
  0.354188;-0.112019;0.928441;,
  -0.341521;0.162334;0.925749;,
  0.345112;0.162105;0.924457;,
  0.994140;0.088598;0.061941;,
  0.994407;-0.085532;0.061958;,
  0.984936;0.153321;-0.079955;,
  0.999163;-0.031380;-0.026237;,
  -0.994407;-0.085532;0.061958;,
  -0.994140;0.088598;0.061941;,
  -0.999163;-0.031380;-0.026237;,
  -0.984936;0.153321;-0.079955;,
  -0.232995;0.937802;-0.257371;,
  0.234255;0.937518;-0.257264;,
  -0.322892;0.773932;-0.544765;,
  0.325357;0.773267;-0.544243;,
  -0.392177;0.446857;-0.804062;,
  0.395498;0.446170;-0.802816;,
  -0.203884;-0.957607;-0.203521;,
  0.204803;-0.957426;-0.203450;,
  -0.320114;-0.822568;-0.470009;,
  0.322347;-0.821942;-0.469578;,
  -0.416482;-0.508238;-0.753815;,
  0.419420;-0.507534;-0.752660;,
  -0.207511;0.943235;0.259319;,
  0.208257;0.943085;0.259267;,
  -0.273674;0.786083;0.554235;,
  0.275298;0.785717;0.553950;,
  -0.324758;0.459205;0.826839;,
  0.327219;0.458809;0.826088;,
  -0.187907;-0.952042;0.241471;,
  0.188243;-0.951979;0.241454;,
  -0.264963;-0.799281;0.539393;,
  0.266372;-0.798985;0.539136;,
  -0.334277;-0.457640;0.823908;,
  0.336886;-0.457205;0.823087;,
  0.407010;0.907293;0.105657;,
  0.388046;0.861649;-0.327079;,
  0.750360;0.653133;0.101867;,
  0.727780;0.629069;-0.273145;,
  0.942342;0.323164;0.086935;,
  0.931001;0.316917;-0.181109;,
  0.407008;-0.907293;0.105657;,
  0.370593;-0.926029;-0.071631;,
  0.750360;-0.653133;0.101867;,
  0.713504;-0.697808;-0.063054;,
  0.942342;-0.323162;0.086936;,
  0.932261;-0.358737;-0.046884;,
  -0.407010;0.907293;0.105657;,
  -0.388046;0.861649;-0.327079;,
  -0.750360;0.653133;0.101867;,
  -0.727780;0.629069;-0.273145;,
  -0.942342;0.323164;0.086935;,
  -0.931001;0.316917;-0.181109;,
  -0.407008;-0.907293;0.105657;,
  -0.370593;-0.926029;-0.071631;,
  -0.750360;-0.653133;0.101867;,
  -0.713504;-0.697808;-0.063054;,
  -0.942342;-0.323162;0.086936;,
  -0.932261;-0.358737;-0.046884;,
  0.538569;0.099425;-0.836694;,
  0.459510;0.449884;-0.765803;,
  0.860774;0.078862;-0.502841;,
  0.793577;0.350360;-0.497478;,
  0.975733;0.011744;-0.218649;,
  0.940914;0.253078;-0.225015;,
  0.501034;-0.141940;0.853709;,
  0.498370;0.174750;0.849170;,
  0.834627;-0.114074;0.538874;,
  0.832376;0.135380;0.537422;,
  0.965217;-0.106402;0.238818;,
  0.964115;0.116530;0.238545;,
  -0.538569;0.099425;-0.836694;,
  -0.459510;0.449884;-0.765803;,
  -0.860774;0.078862;-0.502841;,
  -0.793577;0.350360;-0.497478;,
  -0.975733;0.011744;-0.218649;,
  -0.940914;0.253078;-0.225015;,
  -0.501034;-0.141940;0.853709;,
  -0.498370;0.174750;0.849170;,
  -0.834627;-0.114074;0.538874;,
  -0.832376;0.135380;0.537422;,
  -0.965217;-0.106402;0.238818;,
  -0.964115;0.116530;0.238545;,
  0.539167;0.764840;-0.352589;,
  0.862947;0.392550;-0.318161;,
  0.579723;0.471210;-0.664742;,
  -0.539167;0.764840;-0.352589;,
  -0.862947;0.392550;-0.318161;,
  -0.579723;0.471210;-0.664742;,
  0.499858;-0.815646;-0.291312;,
  0.849807;-0.445906;-0.281061;,
  0.585602;-0.544866;-0.600160;,
  0.539168;0.764840;0.352586;,
  0.862948;0.392550;0.318158;,
  0.579721;0.471208;0.664746;,
  -0.499858;-0.815646;-0.291312;,
  -0.849807;-0.445906;-0.281061;,
  -0.585602;-0.544866;-0.600160;,
  0.539166;-0.764841;0.352587;,
  0.862949;-0.392547;0.318160;,
  0.579724;-0.471209;0.664742;,
  -0.539168;0.764840;0.352586;,
  -0.862948;0.392550;0.318158;,
  -0.579721;0.471208;0.664746;,
  -0.539166;-0.764841;0.352587;,
  -0.862949;-0.392547;0.318160;,
  -0.579724;-0.471209;0.664742;,
  -0.132866;0.951768;-0.276557;,
  0.133433;0.951711;-0.276482;,
  -0.106254;-0.994333;0.003487;,
  0.106254;-0.994333;0.003487;,
  0.995487;0.092643;-0.020545;,
  0.995917;-0.085104;0.030098;,
  -0.995917;-0.085104;0.030098;,
  -0.995487;0.092643;-0.020545;,
  0.405005;0.869640;-0.282305;,
  0.729569;0.648387;-0.217539;,
  0.931886;0.342784;-0.118692;,
  0.407805;-0.912957;0.014343;,
  0.732716;-0.679975;0.027573;,
  0.932687;-0.358794;0.036918;,
  -0.405005;0.869640;-0.282305;,
  -0.729569;0.648387;-0.217539;,
  -0.931886;0.342784;-0.118692;,
  -0.407805;-0.912957;0.014343;,
  -0.732716;-0.679976;0.027573;,
  -0.932687;-0.358794;0.036918;,
  0.000211;0.998089;0.061789;,
  0.000951;0.949580;-0.313523;,
  0.004458;0.570878;-0.821023;,
  0.003717;0.770444;-0.637496;,
  0.000035;-0.999497;-0.031700;,
  0.000082;-0.998088;0.061815;,
  0.003977;-0.127834;0.991788;,
  0.003833;0.184824;0.982764;,
  0.001609;0.967066;-0.254520;,
  0.003251;0.844459;-0.535611;,
  0.004579;0.547185;-0.836999;,
  0.001155;-0.979487;-0.201505;,
  0.002947;-0.873732;-0.486398;,
  0.004110;-0.593463;-0.804851;,
  0.000951;0.966752;0.255713;,
  0.002109;0.842466;0.538745;,
  0.003283;0.542016;0.840362;,
  0.000427;-0.977969;0.208750;,
  0.001818;-0.868867;0.495043;,
  0.003493;-0.542629;0.839965;,
  0.000567;0.967260;-0.253787;,
  0.000000;-1.000000;-0.000000;,
  0.458638;-0.306429;-0.834118;,
  -0.454760;-0.307115;-0.835987;,
  0.590334;-0.278337;-0.757651;,
  -0.583275;-0.280101;-0.762453;;
  224;
  4;7,5,73,72;,
  4;72,73,75,74;,
  4;74,75,77,76;,
  4;76,77,18,19;,
  4;15,13,78,79;,
  4;79,78,80,81;,
  4;81,80,82,83;,
  4;83,82,17,16;,
  4;4,6,84,85;,
  4;85,84,86,87;,
  4;87,86,88,89;,
  4;89,88,22,23;,
  4;12,14,91,90;,
  4;90,91,93,92;,
  4;92,93,95,94;,
  4;94,95,21,20;,
  3;3,49,25;,
  3;49,51,96;,
  3;96,25,49;,
  3;25,96,27;,
  3;51,53,97;,
  3;97,96,51;,
  3;96,97,98;,
  3;98,27,96;,
  3;27,98,29;,
  3;53,18,77;,
  3;77,97,53;,
  3;97,77,75;,
  3;75,98,97;,
  3;98,75,73;,
  3;73,29,98;,
  3;29,73,5;,
  3;24,61,2;,
  3;99,63,61;,
  3;61,24,99;,
  3;26,99,24;,
  3;100,65,63;,
  3;63,99,100;,
  3;101,100,99;,
  3;99,26,101;,
  3;28,101,26;,
  3;89,23,65;,
  3;65,100,89;,
  3;87,89,100;,
  3;100,101,87;,
  3;85,87,101;,
  3;101,28,85;,
  3;4,85,28;,
  3;31,55,9;,
  3;102,57,55;,
  3;55,31,102;,
  3;33,102,31;,
  3;103,59,57;,
  3;57,102,103;,
  3;104,103,102;,
  3;102,33,104;,
  3;35,104,33;,
  3;76,19,59;,
  3;59,103,76;,
  3;74,76,103;,
  3;103,104,74;,
  3;72,74,104;,
  3;104,35,72;,
  3;162,72,35;,
  3;37,48,1;,
  3;105,50,48;,
  3;48,37,105;,
  3;39,105,37;,
  3;106,52,50;,
  3;50,105,106;,
  3;107,106,105;,
  3;105,39,107;,
  3;41,107,39;,
  3;83,16,52;,
  3;52,106,83;,
  3;81,83,106;,
  3;106,107,81;,
  3;79,81,107;,
  3;107,41,79;,
  3;15,79,41;,
  3;8,67,30;,
  3;67,69,108;,
  3;108,30,67;,
  3;30,108,32;,
  3;69,71,109;,
  3;109,108,69;,
  3;108,109,110;,
  3;110,32,108;,
  3;32,110,34;,
  3;71,22,88;,
  3;88,109,71;,
  3;109,88,86;,
  3;86,110,109;,
  3;110,86,84;,
  3;84,34,110;,
  3;34,84,163;,
  3;11,54,43;,
  3;54,56,111;,
  3;111,43,54;,
  3;43,111,45;,
  3;56,58,112;,
  3;112,111,56;,
  3;111,112,113;,
  3;113,45,111;,
  3;45,113,47;,
  3;58,17,82;,
  3;82,112,58;,
  3;112,82,80;,
  3;80,113,112;,
  3;113,80,78;,
  3;78,47,113;,
  3;47,78,13;,
  3;0,60,36;,
  3;60,62,114;,
  3;114,36,60;,
  3;36,114,38;,
  3;62,64,115;,
  3;115,114,62;,
  3;114,115,116;,
  3;116,38,114;,
  3;38,116,40;,
  3;64,21,95;,
  3;95,115,64;,
  3;115,95,93;,
  3;93,116,115;,
  3;116,93,91;,
  3;91,40,116;,
  3;40,91,14;,
  3;42,66,10;,
  3;117,68,66;,
  3;66,42,117;,
  3;44,117,42;,
  3;118,70,68;,
  3;68,117,118;,
  3;119,118,117;,
  3;117,44,119;,
  3;46,119,44;,
  3;94,20,70;,
  3;70,118,94;,
  3;92,94,118;,
  3;118,119,92;,
  3;90,92,119;,
  3;119,46,90;,
  3;12,90,46;,
  4;125,19,18,124;,
  4;125,124,16,17;,
  4;127,23,22,126;,
  4;127,126,20,21;,
  4;121,1,48,128;,
  4;121,128,49,3;,
  4;128,48,50,129;,
  4;128,129,51,49;,
  4;129,50,52,130;,
  4;129,130,53,51;,
  4;130,52,16,124;,
  4;130,124,18,53;,
  4;123,9,55,131;,
  4;123,131,54,11;,
  4;131,55,57,132;,
  4;131,132,56,54;,
  4;132,57,59,133;,
  4;132,133,58,56;,
  4;133,59,19,125;,
  4;133,125,17,58;,
  4;120,2,61,134;,
  4;120,134,60,0;,
  4;134,61,63,135;,
  4;134,135,62,60;,
  4;135,63,65,136;,
  4;135,136,64,62;,
  4;136,65,23,127;,
  4;136,127,21,64;,
  4;122,10,66,137;,
  4;122,137,67,8;,
  4;137,66,68,138;,
  4;137,138,69,67;,
  4;138,68,70,139;,
  4;138,139,71,69;,
  4;139,70,20,126;,
  4;139,126,22,71;,
  4;142,5,7,143;,
  4;142,143,6,4;,
  4;146,13,15,147;,
  4;146,147,14,12;,
  4;141,3,25,148;,
  4;141,148,24,2;,
  4;148,25,27,149;,
  4;148,149,26,24;,
  4;149,27,29,150;,
  4;149,150,28,26;,
  4;150,29,5,142;,
  4;150,142,4,28;,
  4;151,31,9,144;,
  4;151,144,8,30;,
  4;152,33,31,151;,
  4;152,151,30,32;,
  4;153,35,33,152;,
  4;153,152,32,34;,
  4;164,162,35,153;,
  4;165,153,34,163;,
  4;154,37,1,140;,
  4;154,140,0,36;,
  4;155,39,37,154;,
  4;155,154,36,38;,
  4;156,41,39,155;,
  4;156,155,38,40;,
  4;147,15,41,156;,
  4;147,156,40,14;,
  4;145,11,43,157;,
  4;145,157,42,10;,
  4;157,43,45,158;,
  4;157,158,44,42;,
  4;158,45,47,159;,
  4;158,159,46,44;,
  4;159,47,13,146;,
  4;159,146,12,46;,
  4;141,2,120,160;,
  4;141,160,121,3;,
  4;160,120,0,140;,
  4;160,140,1,121;,
  4;145,10,122,161;,
  4;145,161,123,11;,
  4;161,122,8,144;,
  4;161,144,9,123;;
 }
 MeshTextureCoords {
  196;
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
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.520435;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.520435;,
  1.000000;0.000000;,
  1.000000;0.520435;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.520435;,
  1.000000;0.000000;,
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
  0.504587;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.504587;1.000000;,
  0.000000;1.000000;,
  0.504587;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.504587;1.000000;,
  0.000000;1.000000;,
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
  0.504587;1.000000;,
  0.000000;1.000000;,
  0.000000;0.520435;,
  0.504587;0.520435;,
  1.000000;0.520435;,
  1.000000;1.000000;,
  0.504587;0.000000;,
  1.000000;0.000000;,
  0.504587;1.000000;,
  0.000000;1.000000;,
  0.000000;0.479565;,
  0.504587;0.479565;,
  1.000000;0.479565;,
  1.000000;1.000000;,
  0.504587;0.000000;,
  1.000000;0.000000;;
 }
}