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
 223;
 1.24134;0.22550;-1.30860;,
 1.35926;0.16844;-1.30860;,
 1.24134;0.16844;-1.43380;,
 1.45923;0.00615;-1.30860;,
 1.39541;0.00615;-1.47218;,
 1.24134;0.00615;-1.53994;,
 1.52603;-0.23673;-1.30860;,
 1.48789;-0.23673;-1.45973;,
 1.38369;-0.23673;-1.57036;,
 1.24134;-0.23673;-1.61085;,
 1.75409;-1.07504;-1.48238;,
 1.72752;-1.07504;-1.62420;,
 1.65185;-1.07504;-1.74444;,
 1.53860;-1.07504;-1.82476;,
 1.40502;-1.07504;-1.85298;,
 -1.22381;0.16844;-1.43380;,
 -1.34175;0.16844;-1.30860;,
 -1.22381;0.22550;-1.30860;,
 -1.37790;0.00615;-1.47218;,
 -1.44170;0.00615;-1.30860;,
 -1.22381;0.00615;-1.53994;,
 -1.47037;-0.23673;-1.45973;,
 -1.50851;-0.23673;-1.30860;,
 -1.36616;-0.23673;-1.57036;,
 -1.22381;-0.23673;-1.61085;,
 -1.71000;-1.07504;-1.62420;,
 -1.73657;-1.07504;-1.48238;,
 -1.63431;-1.07504;-1.74444;,
 -1.52109;-1.07504;-1.82476;,
 -1.38749;-1.07504;-1.85298;,
 1.24134;-7.20466;-1.43380;,
 1.35926;-7.20466;-1.30860;,
 1.24134;-7.26168;-1.30860;,
 1.39541;-7.04238;-1.47218;,
 1.45923;-7.04238;-1.30860;,
 1.24134;-7.04238;-1.53994;,
 1.48789;-6.79948;-1.45973;,
 1.52603;-6.79948;-1.30860;,
 1.38369;-6.79948;-1.57036;,
 1.24134;-6.79948;-1.61085;,
 1.52603;-6.51296;-1.43380;,
 1.54949;-6.51296;-1.30860;,
 1.45923;-6.51296;-1.53994;,
 1.35926;-6.51296;-1.61085;,
 1.24134;-6.51296;-1.63576;,
 1.24134;0.16844;1.43380;,
 1.35926;0.16844;1.30860;,
 1.24134;0.22550;1.30860;,
 1.39541;0.00615;1.47218;,
 1.45923;0.00615;1.30860;,
 1.24134;0.00615;1.53994;,
 1.48789;-0.23673;1.45973;,
 1.52603;-0.23673;1.30860;,
 1.38369;-0.23673;1.57036;,
 1.24134;-0.23673;1.61085;,
 1.72752;-1.07504;1.62420;,
 1.75409;-1.07504;1.48238;,
 1.65185;-1.07504;1.74444;,
 1.53860;-1.07504;1.82476;,
 1.40502;-1.07504;1.85298;,
 -1.22381;-7.26168;-1.30860;,
 -1.34175;-7.20466;-1.30860;,
 -1.22381;-7.20466;-1.43380;,
 -1.44170;-7.04238;-1.30860;,
 -1.37790;-7.04238;-1.47218;,
 -1.22381;-7.04238;-1.53994;,
 -1.50851;-6.79948;-1.30860;,
 -1.47037;-6.79948;-1.45973;,
 -1.36616;-6.79948;-1.57036;,
 -1.22381;-6.79948;-1.61085;,
 -1.53197;-6.51296;-1.30860;,
 -1.50851;-6.51296;-1.43380;,
 -1.44170;-6.51296;-1.53994;,
 -1.34175;-6.51296;-1.61085;,
 -1.22381;-6.51296;-1.63576;,
 1.24134;-7.26168;1.30860;,
 1.35926;-7.20466;1.30860;,
 1.24134;-7.20466;1.43380;,
 1.45923;-7.04238;1.30860;,
 1.39541;-7.04238;1.47218;,
 1.24134;-7.04238;1.53994;,
 1.52603;-6.79948;1.30860;,
 1.48789;-6.79948;1.45973;,
 1.38369;-6.79948;1.57036;,
 1.24134;-6.79948;1.61085;,
 1.54949;-6.51296;1.30860;,
 1.52603;-6.51296;1.43380;,
 1.45923;-6.51296;1.53994;,
 1.35926;-6.51296;1.61085;,
 1.24134;-6.51296;1.63576;,
 -1.22381;0.22550;1.30860;,
 -1.34175;0.16844;1.30860;,
 -1.22381;0.16844;1.43380;,
 -1.44170;0.00615;1.30860;,
 -1.37790;0.00615;1.47218;,
 -1.22381;0.00615;1.53994;,
 -1.50851;-0.23673;1.30860;,
 -1.47037;-0.23673;1.45973;,
 -1.36616;-0.23673;1.57036;,
 -1.22381;-0.23673;1.61085;,
 -1.73657;-1.07504;1.48238;,
 -1.71000;-1.07504;1.62420;,
 -1.63431;-1.07504;1.74444;,
 -1.52109;-1.07504;1.82476;,
 -1.38749;-1.07504;1.85298;,
 -1.22381;-7.20466;1.43380;,
 -1.34175;-7.20466;1.30860;,
 -1.22381;-7.26168;1.30860;,
 -1.37790;-7.04238;1.47218;,
 -1.44170;-7.04238;1.30860;,
 -1.22381;-7.04238;1.53994;,
 -1.47037;-6.79948;1.45973;,
 -1.50851;-6.79948;1.30860;,
 -1.36616;-6.79948;1.57036;,
 -1.22381;-6.79948;1.61085;,
 -1.50851;-6.51296;1.43380;,
 -1.53197;-6.51296;1.30860;,
 -1.44170;-6.51296;1.53994;,
 -1.34175;-6.51296;1.61085;,
 -1.22381;-6.51296;1.63576;,
 1.30437;-4.20785;-1.71941;,
 1.42832;-4.20785;-1.69323;,
 1.53341;-4.20785;-1.61869;,
 1.60362;-4.20785;-1.50712;,
 1.62828;-4.20785;-1.37552;,
 1.30437;-4.20785;1.71941;,
 1.42832;-4.20785;1.69323;,
 1.53341;-4.20785;1.61869;,
 1.60362;-4.20785;1.50712;,
 1.62828;-4.20785;1.37552;,
 -1.28684;-4.20785;-1.71941;,
 -1.41081;-4.20785;-1.69323;,
 -1.51588;-4.20785;-1.61869;,
 -1.58610;-4.20785;-1.50712;,
 -1.61076;-4.20785;-1.37552;,
 -1.28684;-4.20785;1.71941;,
 -1.41081;-4.20785;1.69323;,
 -1.51588;-4.20785;1.61869;,
 -1.58610;-4.20785;1.50712;,
 -1.61076;-4.20785;1.37552;,
 1.40502;-2.06391;-1.85298;,
 1.53860;-2.06391;-1.82476;,
 1.65185;-2.06391;-1.74444;,
 1.72752;-2.06391;-1.62420;,
 1.75409;-2.06391;-1.48238;,
 1.53860;-2.06391;1.82476;,
 1.40502;-2.06391;1.85298;,
 1.65185;-2.06391;1.74444;,
 1.72752;-2.06391;1.62420;,
 1.75409;-2.06391;1.48238;,
 -1.52109;-2.06391;-1.82476;,
 -1.38749;-2.06391;-1.85298;,
 -1.63431;-2.06391;-1.74444;,
 -1.71000;-2.06391;-1.62420;,
 -1.73657;-2.06391;-1.48238;,
 -1.38749;-2.06391;1.85298;,
 -1.52109;-2.06391;1.82476;,
 -1.63431;-2.06391;1.74444;,
 -1.71000;-2.06391;1.62420;,
 -1.73657;-2.06391;1.48238;,
 1.50600;0.22550;0.03071;,
 1.64924;0.16844;0.03071;,
 1.77068;0.00615;0.03071;,
 1.85182;-0.23673;0.03071;,
 2.12885;-1.07504;0.03071;,
 1.50600;-7.26168;0.03071;,
 1.64924;-7.20466;0.03071;,
 1.77068;-7.04238;0.03071;,
 1.85182;-6.79948;0.03071;,
 1.88032;-6.51296;0.03071;,
 -1.48847;0.22550;0.03071;,
 -1.63173;0.16844;0.03071;,
 -1.75314;0.00615;0.03071;,
 -1.83430;-0.23673;0.03071;,
 -2.11133;-1.07504;0.03071;,
 -1.48847;-7.26168;0.03071;,
 -1.63173;-7.20466;0.03071;,
 -1.75314;-7.04238;0.03071;,
 -1.83430;-6.79948;0.03071;,
 -1.86280;-6.51296;0.03071;,
 1.97603;-4.20785;0.03071;,
 -1.95851;-4.20785;0.03071;,
 2.12885;-2.06391;0.03071;,
 -2.11133;-2.06391;0.03071;,
 -0.01115;0.22550;-1.51225;,
 1.24134;0.22550;-1.30860;,
 1.24134;0.16844;-1.43380;,
 -0.01115;0.16844;-1.65693;,
 1.24134;0.00615;-1.53994;,
 -0.01115;0.00615;-1.77959;,
 1.24134;-0.23673;-1.61085;,
 -0.01115;-0.23673;-1.86153;,
 1.40502;-1.07504;-1.85298;,
 -0.01115;-1.07504;-2.14134;,
 -0.01115;-7.20466;-1.65693;,
 1.24134;-7.20466;-1.43380;,
 1.24134;-7.26168;-1.30860;,
 -0.01115;-7.26168;-1.51225;,
 -0.01115;-7.04238;-1.77959;,
 1.24134;-7.04238;-1.53994;,
 -0.01115;-6.79948;-1.86153;,
 1.24134;-6.79948;-1.61085;,
 -0.01115;-6.51296;-1.89032;,
 1.24134;-6.51296;-1.63576;,
 -0.01115;0.16844;1.65693;,
 -0.01115;0.22550;1.51225;,
 -0.01115;0.00615;1.77959;,
 -0.01115;-0.23673;1.86153;,
 -0.01115;-1.07504;2.14134;,
 -0.01115;-7.26168;1.51225;,
 -0.01115;-7.20466;1.65693;,
 -0.01115;-7.04238;1.77959;,
 -0.01115;-6.79948;1.86153;,
 -0.01115;-6.51296;1.89032;,
 -0.01115;-4.20785;-1.98699;,
 1.30437;-4.20785;-1.71941;,
 -0.01115;-4.20785;1.98699;,
 1.40502;-2.06391;-1.85298;,
 -0.01115;-2.06391;-2.14134;,
 -0.01115;-2.06391;2.14134;,
 -0.01115;0.22550;0.03071;,
 1.50600;0.22550;0.03071;,
 -0.01115;-7.26168;0.03071;;
 
 272;
 3;0,1,2;,
 3;1,3,4;,
 3;4,2,1;,
 3;2,4,5;,
 3;3,6,7;,
 3;7,4,3;,
 3;4,7,8;,
 3;8,5,4;,
 3;5,8,9;,
 3;6,10,11;,
 3;11,7,6;,
 3;7,11,12;,
 3;12,8,7;,
 3;8,12,13;,
 3;13,9,8;,
 3;9,13,14;,
 3;15,16,17;,
 3;18,19,16;,
 3;16,15,18;,
 3;20,18,15;,
 3;21,22,19;,
 3;19,18,21;,
 3;23,21,18;,
 3;18,20,23;,
 3;24,23,20;,
 3;25,26,22;,
 3;22,21,25;,
 3;27,25,21;,
 3;21,23,27;,
 3;28,27,23;,
 3;23,24,28;,
 3;29,28,24;,
 3;30,31,32;,
 3;33,34,31;,
 3;31,30,33;,
 3;35,33,30;,
 3;36,37,34;,
 3;34,33,36;,
 3;38,36,33;,
 3;33,35,38;,
 3;39,38,35;,
 3;40,41,37;,
 3;37,36,40;,
 3;42,40,36;,
 3;36,38,42;,
 3;43,42,38;,
 3;38,39,43;,
 3;44,43,39;,
 3;45,46,47;,
 3;48,49,46;,
 3;46,45,48;,
 3;50,48,45;,
 3;51,52,49;,
 3;49,48,51;,
 3;53,51,48;,
 3;48,50,53;,
 3;54,53,50;,
 3;55,56,52;,
 3;52,51,55;,
 3;57,55,51;,
 3;51,53,57;,
 3;58,57,53;,
 3;53,54,58;,
 3;59,58,54;,
 3;60,61,62;,
 3;61,63,64;,
 3;64,62,61;,
 3;62,64,65;,
 3;63,66,67;,
 3;67,64,63;,
 3;64,67,68;,
 3;68,65,64;,
 3;65,68,69;,
 3;66,70,71;,
 3;71,67,66;,
 3;67,71,72;,
 3;72,68,67;,
 3;68,72,73;,
 3;73,69,68;,
 3;69,73,74;,
 3;75,76,77;,
 3;76,78,79;,
 3;79,77,76;,
 3;77,79,80;,
 3;78,81,82;,
 3;82,79,78;,
 3;79,82,83;,
 3;83,80,79;,
 3;80,83,84;,
 3;81,85,86;,
 3;86,82,81;,
 3;82,86,87;,
 3;87,83,82;,
 3;83,87,88;,
 3;88,84,83;,
 3;84,88,89;,
 3;90,91,92;,
 3;91,93,94;,
 3;94,92,91;,
 3;92,94,95;,
 3;93,96,97;,
 3;97,94,93;,
 3;94,97,98;,
 3;98,95,94;,
 3;95,98,99;,
 3;96,100,101;,
 3;101,97,96;,
 3;97,101,102;,
 3;102,98,97;,
 3;98,102,103;,
 3;103,99,98;,
 3;99,103,104;,
 3;105,106,107;,
 3;108,109,106;,
 3;106,105,108;,
 3;110,108,105;,
 3;111,112,109;,
 3;109,108,111;,
 3;113,111,108;,
 3;108,110,113;,
 3;114,113,110;,
 3;115,116,112;,
 3;112,111,115;,
 3;117,115,111;,
 3;111,113,117;,
 3;118,117,113;,
 3;113,114,118;,
 3;119,118,114;,
 4;120,121,43,44;,
 4;121,122,42,43;,
 4;122,123,40,42;,
 4;123,124,41,40;,
 4;125,89,88,126;,
 4;126,88,87,127;,
 4;127,87,86,128;,
 4;128,86,85,129;,
 4;130,74,73,131;,
 4;131,73,72,132;,
 4;132,72,71,133;,
 4;133,71,70,134;,
 4;135,136,118,119;,
 4;136,137,117,118;,
 4;137,138,115,117;,
 4;138,139,116,115;,
 4;140,14,13,141;,
 4;140,141,121,120;,
 4;141,13,12,142;,
 4;141,142,122,121;,
 4;142,12,11,143;,
 4;142,143,123,122;,
 4;143,11,10,144;,
 4;143,144,124,123;,
 4;145,58,59,146;,
 4;145,146,125,126;,
 4;147,57,58,145;,
 4;147,145,126,127;,
 4;148,55,57,147;,
 4;148,147,127,128;,
 4;149,56,55,148;,
 4;149,148,128,129;,
 4;150,28,29,151;,
 4;150,151,130,131;,
 4;152,27,28,150;,
 4;152,150,131,132;,
 4;153,25,27,152;,
 4;153,152,132,133;,
 4;154,26,25,153;,
 4;154,153,133,134;,
 4;155,104,103,156;,
 4;155,156,136,135;,
 4;156,103,102,157;,
 4;156,157,137,136;,
 4;157,102,101,158;,
 4;157,158,138,137;,
 4;158,101,100,159;,
 4;158,159,139,138;,
 4;160,47,46,161;,
 4;160,161,1,0;,
 4;161,46,49,162;,
 4;161,162,3,1;,
 4;162,49,52,163;,
 4;162,163,6,3;,
 4;163,52,56,164;,
 4;163,164,10,6;,
 4;165,32,31,166;,
 4;165,166,76,75;,
 4;166,31,34,167;,
 4;166,167,78,76;,
 4;167,34,37,168;,
 4;167,168,81,78;,
 4;168,37,41,169;,
 4;168,169,85,81;,
 4;170,17,16,171;,
 4;170,171,91,90;,
 4;171,16,19,172;,
 4;171,172,93,91;,
 4;172,19,22,173;,
 4;172,173,96,93;,
 4;173,22,26,174;,
 4;173,174,100,96;,
 4;175,107,106,176;,
 4;175,176,61,60;,
 4;176,106,109,177;,
 4;176,177,63,61;,
 4;177,109,112,178;,
 4;177,178,66,63;,
 4;178,112,116,179;,
 4;178,179,70,66;,
 4;169,41,124,180;,
 4;169,180,129,85;,
 4;181,134,70,179;,
 4;181,179,116,139;,
 4;164,56,149,182;,
 4;164,182,144,10;,
 4;182,149,129,180;,
 4;182,180,124,144;,
 4;174,26,154,183;,
 4;174,183,159,100;,
 4;183,154,134,181;,
 4;183,181,139,159;,
 4;184,185,186,187;,
 4;184,187,15,17;,
 4;187,186,188,189;,
 4;187,189,20,15;,
 4;189,188,190,191;,
 4;189,191,24,20;,
 4;191,190,192,193;,
 4;191,193,29,24;,
 4;194,195,196,197;,
 4;194,197,60,62;,
 4;198,199,195,194;,
 4;198,194,62,65;,
 4;200,201,199,198;,
 4;200,198,65,69;,
 4;202,203,201,200;,
 4;202,200,69,74;,
 4;204,45,47,205;,
 4;204,205,90,92;,
 4;206,50,45,204;,
 4;206,204,92,95;,
 4;207,54,50,206;,
 4;207,206,95,99;,
 4;208,59,54,207;,
 4;208,207,99,104;,
 4;209,75,77,210;,
 4;209,210,105,107;,
 4;210,77,80,211;,
 4;210,211,110,105;,
 4;211,80,84,212;,
 4;211,212,114,110;,
 4;212,84,89,213;,
 4;212,213,119,114;,
 4;202,74,130,214;,
 4;202,214,215,203;,
 4;216,135,119,213;,
 4;216,213,89,125;,
 4;193,192,217,218;,
 4;193,218,151,29;,
 4;218,217,215,214;,
 4;218,214,130,151;,
 4;208,104,155,219;,
 4;208,219,146,59;,
 4;219,155,135,216;,
 4;219,216,125,146;,
 4;184,17,170,220;,
 4;184,220,221,185;,
 4;220,170,90,205;,
 4;220,205,47,160;,
 4;209,107,175,222;,
 4;209,222,165,75;,
 4;222,175,60,197;,
 4;222,197,32,165;;
 
 MeshMaterialList {
  10;
  272;
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
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\student\\Documents\\Visual Studio 2015\\Projects\\3D�l����\\data\\TEXTURE\\���ʕ�.jpeg";
   }
  }
  Material {
   0.178824;0.156863;0.090980;1.000000;;
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
   0.251200;0.392000;0.232000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.339200;0.339200;0.339200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  210;
  -0.226039;0.948538;0.221771;,
  0.225528;0.948651;0.221807;,
  -0.226107;0.948753;-0.220779;,
  0.225595;0.948866;-0.220815;,
  -0.203029;0.155967;-0.966671;,
  0.200235;0.155932;-0.967260;,
  -0.205219;-0.064589;-0.976583;,
  0.202157;-0.064611;-0.977219;,
  -0.225975;-0.948815;-0.220649;,
  0.225464;-0.948928;-0.220685;,
  -0.225907;-0.948600;0.221641;,
  0.225396;-0.948713;0.221677;,
  -0.205219;-0.064589;0.976583;,
  0.202157;-0.064611;0.977219;,
  -0.203029;0.155967;0.966671;,
  0.200235;0.155932;0.967260;,
  0.965091;0.150555;0.214320;,
  0.974300;-0.061763;0.216621;,
  0.966174;0.150482;-0.209436;,
  0.975473;-0.061802;-0.211267;,
  -0.974300;-0.061763;0.216621;,
  -0.965091;0.150555;0.214320;,
  -0.975473;-0.061802;-0.211267;,
  -0.966174;0.150482;-0.209436;,
  -0.319464;0.729756;-0.604482;,
  0.318135;0.730081;-0.604790;,
  -0.269943;0.400860;-0.875467;,
  0.267870;0.401105;-0.875991;,
  -0.220572;0.301260;-0.927680;,
  0.218316;0.301320;-0.928194;,
  -0.319417;-0.729845;-0.604400;,
  0.318087;-0.730171;-0.604708;,
  -0.269943;-0.400857;-0.875468;,
  0.267870;-0.401102;-0.875992;,
  -0.227866;-0.171446;-0.958480;,
  0.225476;-0.171547;-0.959027;,
  -0.319464;0.729756;0.604482;,
  0.318135;0.730081;0.604790;,
  -0.269943;0.400860;0.875467;,
  0.267870;0.401105;0.875991;,
  -0.220572;0.301260;0.927680;,
  0.218316;0.301320;0.928194;,
  -0.319417;-0.729845;0.604400;,
  0.318087;-0.730171;0.604708;,
  -0.269943;-0.400857;0.875468;,
  0.267870;-0.401102;0.875992;,
  -0.227866;-0.171446;0.958480;,
  0.225476;-0.171547;0.959027;,
  0.621537;0.718657;0.311807;,
  0.622112;0.719221;-0.309352;,
  0.883216;0.385842;0.266563;,
  0.884142;0.386252;-0.262874;,
  0.930967;0.289154;0.222915;,
  0.931878;0.289242;-0.218959;,
  0.621454;-0.718749;0.311761;,
  0.622028;-0.719313;-0.309306;,
  0.883217;-0.385840;0.266564;,
  0.884143;-0.386250;-0.262874;,
  0.959414;-0.163676;0.229639;,
  0.960376;-0.163858;-0.225451;,
  -0.621540;0.718655;0.311807;,
  -0.622114;0.719219;-0.309352;,
  -0.883235;0.385824;0.266527;,
  -0.884161;0.386234;-0.262837;,
  -0.930962;0.289172;0.222913;,
  -0.931873;0.289259;-0.218957;,
  -0.621457;-0.718747;0.311761;,
  -0.622031;-0.719310;-0.309306;,
  -0.883236;-0.385821;0.266527;,
  -0.884162;-0.386231;-0.262838;,
  -0.959412;-0.163694;0.229637;,
  -0.960373;-0.163876;-0.225450;,
  0.374788;-0.071309;-0.924364;,
  0.368294;0.199071;-0.908146;,
  0.724948;-0.069124;-0.685326;,
  0.710749;0.208552;-0.671820;,
  0.937873;-0.068096;-0.340230;,
  0.922799;0.190846;-0.334693;,
  0.374788;-0.071309;0.924364;,
  0.368294;0.199071;0.908146;,
  0.724948;-0.069124;0.685326;,
  0.710749;0.208552;0.671820;,
  0.937873;-0.068096;0.340230;,
  0.922799;0.190846;0.334693;,
  -0.374809;-0.071319;-0.924355;,
  -0.368328;0.199076;-0.908132;,
  -0.724949;-0.069124;-0.685326;,
  -0.710745;0.208548;-0.671825;,
  -0.937864;-0.068094;-0.340255;,
  -0.922783;0.190848;-0.334736;,
  -0.374809;-0.071319;0.924355;,
  -0.368328;0.199076;0.908132;,
  -0.724949;-0.069124;0.685326;,
  -0.710745;0.208548;0.671825;,
  -0.937864;-0.068094;0.340255;,
  -0.922783;0.190848;0.334736;,
  0.647788;0.448299;-0.615953;,
  0.840174;0.306601;-0.447329;,
  0.484516;0.315295;-0.815986;,
  -0.647792;0.448290;-0.615956;,
  -0.840167;0.306598;-0.447345;,
  -0.484516;0.315285;-0.815990;,
  0.647788;-0.448301;-0.615952;,
  0.866202;-0.188403;-0.462815;,
  0.501989;-0.194480;-0.842725;,
  0.647788;0.448299;0.615953;,
  0.840174;0.306601;0.447329;,
  0.484516;0.315295;0.815986;,
  -0.647792;-0.448292;-0.615955;,
  -0.866198;-0.188397;-0.462825;,
  -0.501983;-0.194474;-0.842729;,
  0.647788;-0.448301;0.615952;,
  0.866202;-0.188403;0.462815;,
  0.501989;-0.194480;0.842725;,
  -0.647792;0.448290;0.615956;,
  -0.840167;0.306598;0.447345;,
  -0.484516;0.315285;0.815990;,
  -0.647792;-0.448292;0.615955;,
  -0.866198;-0.188397;0.462825;,
  -0.501983;-0.194474;0.842729;,
  -0.205634;-0.055759;-0.977039;,
  0.202689;-0.055738;-0.977656;,
  -0.205634;-0.055759;0.977039;,
  0.202689;-0.055738;0.977656;,
  0.974678;-0.053750;0.217056;,
  0.975813;-0.053709;-0.211907;,
  -0.974678;-0.053748;0.217055;,
  -0.975813;-0.053709;-0.211907;,
  0.400166;-0.060662;-0.914433;,
  0.724903;-0.063502;-0.685918;,
  0.929509;-0.058224;-0.364175;,
  0.400166;-0.060662;0.914433;,
  0.724903;-0.063502;0.685918;,
  0.929509;-0.058224;0.364175;,
  -0.400197;-0.060662;-0.914419;,
  -0.724910;-0.063501;-0.685910;,
  -0.929495;-0.058225;-0.364211;,
  -0.400197;-0.060662;0.914419;,
  -0.724910;-0.063501;0.685910;,
  -0.929495;-0.058225;0.364211;,
  -0.205758;-0.035231;-0.977968;,
  0.202956;-0.035218;-0.978554;,
  -0.205758;-0.035231;0.977968;,
  0.202956;-0.035218;0.978554;,
  0.975557;-0.033964;0.217104;,
  0.976636;-0.033937;-0.212205;,
  -0.975557;-0.033961;0.217104;,
  -0.976636;-0.033937;-0.212205;,
  0.400615;-0.038330;-0.915444;,
  0.725773;-0.040125;-0.686763;,
  0.930456;-0.036791;-0.364552;,
  0.400615;-0.038330;0.915444;,
  0.725773;-0.040125;0.686763;,
  0.930456;-0.036791;0.364552;,
  -0.400654;-0.038331;-0.915427;,
  -0.725777;-0.040124;-0.686759;,
  -0.930437;-0.036791;-0.364601;,
  -0.400654;-0.038331;0.915427;,
  -0.725777;-0.040124;0.686759;,
  -0.930437;-0.036791;0.364601;,
  -0.205551;0.978646;0.001012;,
  0.205579;0.978640;0.001012;,
  -0.205425;-0.978672;0.001011;,
  0.205453;-0.978667;0.001011;,
  0.987453;0.157832;0.004998;,
  0.997810;-0.065917;0.005482;,
  -0.997810;-0.065917;0.005482;,
  -0.987453;0.157832;0.004998;,
  0.638219;0.769848;0.003261;,
  0.901747;0.432239;0.004797;,
  0.953559;0.301165;0.005067;,
  0.638108;-0.769940;0.003260;,
  0.901745;-0.432241;0.004797;,
  0.981402;-0.191889;0.005382;,
  -0.638237;0.769833;0.003261;,
  -0.901757;0.432216;0.004797;,
  -0.953550;0.301192;0.005067;,
  -0.638125;-0.769926;0.003261;,
  -0.901756;-0.432219;0.004797;,
  -0.981396;-0.191917;0.005382;,
  0.998400;-0.056304;0.005271;,
  -0.998400;-0.056301;0.005271;,
  0.999354;-0.035579;0.005017;,
  -0.999354;-0.035576;0.005017;,
  -0.000553;0.979949;0.199246;,
  -0.000553;0.979949;-0.199246;,
  -0.002867;0.159537;-0.987188;,
  -0.003144;-0.067627;-0.997706;,
  -0.000553;-0.979974;-0.199123;,
  -0.000553;-0.979974;0.199123;,
  -0.003144;-0.067627;0.997706;,
  -0.002867;0.159537;0.987188;,
  -0.001821;0.778647;-0.627459;,
  -0.002722;0.443426;-0.896307;,
  -0.002897;0.307329;-0.951599;,
  -0.001820;-0.778736;-0.627349;,
  -0.002722;-0.443428;-0.896306;,
  -0.003080;-0.197886;-0.980220;,
  -0.001821;0.778647;0.627459;,
  -0.002722;0.443426;0.896307;,
  -0.002897;0.307329;0.951599;,
  -0.001820;-0.778736;0.627349;,
  -0.002722;-0.443428;0.896306;,
  -0.003080;-0.197886;0.980220;,
  -0.003024;-0.056861;-0.998378;,
  -0.003024;-0.056861;0.998378;,
  -0.002878;-0.035929;-0.999350;,
  -0.002878;-0.035929;0.999350;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;;
  272;
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
  3;7,72,35;,
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
  3;34,84,6;,
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
  4;121,128,72,7;,
  4;128,129,74,72;,
  4;129,130,76,74;,
  4;130,125,19,76;,
  4;123,13,78,131;,
  4;131,78,80,132;,
  4;132,80,82,133;,
  4;133,82,17,124;,
  4;120,6,84,134;,
  4;134,84,86,135;,
  4;135,86,88,136;,
  4;136,88,22,127;,
  4;122,137,90,12;,
  4;137,138,92,90;,
  4;138,139,94,92;,
  4;139,126,20,94;,
  4;141,5,73,148;,
  4;141,148,128,121;,
  4;148,73,75,149;,
  4;148,149,129,128;,
  4;149,75,77,150;,
  4;149,150,130,129;,
  4;150,77,18,145;,
  4;150,145,125,130;,
  4;151,79,15,143;,
  4;151,143,123,131;,
  4;152,81,79,151;,
  4;152,151,131,132;,
  4;153,83,81,152;,
  4;153,152,132,133;,
  4;144,16,83,153;,
  4;144,153,133,124;,
  4;154,85,4,140;,
  4;154,140,120,134;,
  4;155,87,85,154;,
  4;155,154,134,135;,
  4;156,89,87,155;,
  4;156,155,135,136;,
  4;147,23,89,156;,
  4;147,156,136,127;,
  4;142,14,91,157;,
  4;142,157,137,122;,
  4;157,91,93,158;,
  4;157,158,138,137;,
  4;158,93,95,159;,
  4;158,159,139,138;,
  4;159,95,21,146;,
  4;159,146,126,139;,
  4;161,1,48,168;,
  4;161,168,49,3;,
  4;168,48,50,169;,
  4;168,169,51,49;,
  4;169,50,52,170;,
  4;169,170,53,51;,
  4;170,52,16,164;,
  4;170,164,18,53;,
  4;163,9,55,171;,
  4;163,171,54,11;,
  4;171,55,57,172;,
  4;171,172,56,54;,
  4;172,57,59,173;,
  4;172,173,58,56;,
  4;173,59,19,165;,
  4;173,165,17,58;,
  4;160,2,61,174;,
  4;160,174,60,0;,
  4;174,61,63,175;,
  4;174,175,62,60;,
  4;175,63,65,176;,
  4;175,176,64,62;,
  4;176,65,23,167;,
  4;176,167,21,64;,
  4;162,10,66,177;,
  4;162,177,67,8;,
  4;177,66,68,178;,
  4;177,178,69,67;,
  4;178,68,70,179;,
  4;178,179,71,69;,
  4;179,70,20,166;,
  4;179,166,22,71;,
  4;165,19,125,180;,
  4;165,180,124,17;,
  4;181,127,22,166;,
  4;181,166,20,126;,
  4;164,16,144,182;,
  4;164,182,145,18;,
  4;182,144,124,180;,
  4;182,180,125,145;,
  4;167,23,147,183;,
  4;167,183,146,21;,
  4;183,147,127,181;,
  4;183,181,126,146;,
  4;185,3,25,192;,
  4;185,192,24,2;,
  4;192,25,27,193;,
  4;192,193,26,24;,
  4;193,27,29,194;,
  4;193,194,28,26;,
  4;194,29,5,186;,
  4;194,186,4,28;,
  4;195,31,9,188;,
  4;195,188,8,30;,
  4;196,33,31,195;,
  4;196,195,30,32;,
  4;197,35,33,196;,
  4;197,196,32,34;,
  4;187,7,35,197;,
  4;187,197,34,6;,
  4;198,37,1,184;,
  4;198,184,0,36;,
  4;199,39,37,198;,
  4;199,198,36,38;,
  4;200,41,39,199;,
  4;200,199,38,40;,
  4;191,15,41,200;,
  4;191,200,40,14;,
  4;189,11,43,201;,
  4;189,201,42,10;,
  4;201,43,45,202;,
  4;201,202,44,42;,
  4;202,45,47,203;,
  4;202,203,46,44;,
  4;203,47,13,190;,
  4;203,190,12,46;,
  4;187,6,120,204;,
  4;187,204,121,7;,
  4;205,122,12,190;,
  4;205,190,13,123;,
  4;186,5,141,206;,
  4;186,206,140,4;,
  4;206,141,121,204;,
  4;206,204,120,140;,
  4;191,14,142,207;,
  4;191,207,143,15;,
  4;207,142,122,205;,
  4;207,205,123,143;,
  4;185,2,160,208;,
  4;185,208,161,3;,
  4;208,160,0,184;,
  4;208,184,1,161;,
  4;189,10,162,209;,
  4;189,209,163,11;,
  4;209,162,8,188;,
  4;209,188,9,163;;
 }
 MeshTextureCoords {
  223;
  0.120803;0.488725;,
  0.128022;0.491578;,
  0.113569;0.491578;,
  0.133653;0.499692;,
  0.120740;0.499692;,
  0.107978;0.499692;,
  0.137184;0.511837;,
  0.126520;0.511837;,
  0.114956;0.511837;,
  0.104495;0.511837;,
  0.138330;0.553752;,
  0.129905;0.553752;,
  0.120662;0.553752;,
  0.111491;0.553752;,
  0.103253;0.553752;,
  0.887550;0.491578;,
  0.873009;0.491578;,
  0.880327;0.488725;,
  0.880263;0.499692;,
  0.867304;0.499692;,
  0.893126;0.499692;,
  0.874422;0.511837;,
  0.863725;0.511837;,
  0.886050;0.511837;,
  0.896597;0.511837;,
  0.870905;0.553752;,
  0.862458;0.553752;,
  0.880186;0.553752;,
  0.889405;0.553752;,
  0.897707;0.553752;,
  0.113569;0.860233;,
  0.128022;0.860233;,
  0.120803;0.863084;,
  0.120740;0.852119;,
  0.133653;0.852119;,
  0.107978;0.852119;,
  0.126520;0.839974;,
  0.137184;0.839974;,
  0.114956;0.839974;,
  0.104495;0.839974;,
  0.129958;0.825648;,
  0.138383;0.825648;,
  0.120718;0.825648;,
  0.111551;0.825648;,
  0.103317;0.825648;,
  0.386431;0.491578;,
  0.371978;0.491578;,
  0.379197;0.488725;,
  0.379260;0.499692;,
  0.366347;0.499692;,
  0.392022;0.499692;,
  0.373480;0.511837;,
  0.362816;0.511837;,
  0.385044;0.511837;,
  0.395505;0.511837;,
  0.370095;0.553752;,
  0.361670;0.553752;,
  0.379338;0.553752;,
  0.388509;0.553752;,
  0.396747;0.553752;,
  0.880327;0.863084;,
  0.873009;0.860233;,
  0.887550;0.860233;,
  0.867304;0.852119;,
  0.880263;0.852119;,
  0.893126;0.852119;,
  0.863725;0.839974;,
  0.874422;0.839974;,
  0.886050;0.839974;,
  0.896597;0.839974;,
  0.862510;0.825648;,
  0.870960;0.825648;,
  0.880242;0.825648;,
  0.889465;0.825648;,
  0.897771;0.825648;,
  0.379197;0.863084;,
  0.371978;0.860233;,
  0.386431;0.860233;,
  0.366347;0.852119;,
  0.379260;0.852119;,
  0.392022;0.852119;,
  0.362816;0.839974;,
  0.373480;0.839974;,
  0.385044;0.839974;,
  0.395505;0.839974;,
  0.361617;0.825648;,
  0.370042;0.825648;,
  0.379282;0.825648;,
  0.388449;0.825648;,
  0.396683;0.825648;,
  0.619673;0.488725;,
  0.626991;0.491578;,
  0.612450;0.491578;,
  0.632696;0.499692;,
  0.619737;0.499692;,
  0.606874;0.499692;,
  0.636275;0.511837;,
  0.625578;0.511837;,
  0.613950;0.511837;,
  0.603403;0.511837;,
  0.637542;0.553752;,
  0.629095;0.553752;,
  0.619814;0.553752;,
  0.610595;0.553752;,
  0.602293;0.553752;,
  0.612450;0.860233;,
  0.626991;0.860233;,
  0.619673;0.863084;,
  0.619737;0.852119;,
  0.632696;0.852119;,
  0.606874;0.852119;,
  0.625578;0.839974;,
  0.636275;0.839974;,
  0.613950;0.839974;,
  0.603403;0.839974;,
  0.629040;0.825648;,
  0.637490;0.825648;,
  0.619758;0.825648;,
  0.610535;0.825648;,
  0.602229;0.825648;,
  0.103290;0.710392;,
  0.111526;0.710392;,
  0.120695;0.710392;,
  0.129936;0.710392;,
  0.138361;0.710392;,
  0.396710;0.710392;,
  0.388474;0.710392;,
  0.379305;0.710392;,
  0.370064;0.710392;,
  0.361639;0.710392;,
  0.897745;0.710392;,
  0.889441;0.710392;,
  0.880218;0.710392;,
  0.870937;0.710392;,
  0.862489;0.710392;,
  0.602255;0.710392;,
  0.610559;0.710392;,
  0.619782;0.710392;,
  0.629063;0.710392;,
  0.637511;0.710392;,
  0.103253;0.603195;,
  0.111491;0.603195;,
  0.120662;0.603195;,
  0.129905;0.603195;,
  0.138330;0.603195;,
  0.388509;0.603195;,
  0.396747;0.603195;,
  0.379338;0.603195;,
  0.370095;0.603195;,
  0.361670;0.603195;,
  0.889405;0.603195;,
  0.897707;0.603195;,
  0.880186;0.603195;,
  0.870905;0.603195;,
  0.862458;0.603195;,
  0.602293;0.603195;,
  0.610595;0.603195;,
  0.619814;0.603195;,
  0.629095;0.603195;,
  0.637542;0.603195;,
  0.253245;0.488725;,
  0.252963;0.491578;,
  0.252760;0.499692;,
  0.252639;0.511837;,
  0.252296;0.553752;,
  0.253245;0.863084;,
  0.252963;0.860233;,
  0.252760;0.852119;,
  0.252639;0.839974;,
  0.252599;0.825648;,
  0.746717;0.488725;,
  0.747005;0.491578;,
  0.747212;0.499692;,
  0.747336;0.511837;,
  0.747685;0.553752;,
  0.746717;0.863084;,
  0.747005;0.860233;,
  0.747212;0.852119;,
  0.747336;0.839974;,
  0.747376;0.825648;,
  0.252473;0.710392;,
  0.747505;0.710392;,
  0.252296;0.603195;,
  0.747685;0.603195;,
  0.998827;0.488725;,
  1.120803;0.488725;,
  1.113569;0.491578;,
  0.998929;0.491578;,
  1.107978;0.499692;,
  0.999003;0.499692;,
  1.104495;0.511837;,
  0.999047;0.511837;,
  1.103253;0.553752;,
  0.999171;0.553752;,
  0.998929;0.860233;,
  1.113569;0.860233;,
  1.120803;0.863084;,
  0.998827;0.863084;,
  0.999003;0.852119;,
  1.107978;0.852119;,
  0.999047;0.839974;,
  1.104495;0.839974;,
  0.999061;0.825648;,
  1.103317;0.825648;,
  0.501071;0.491578;,
  0.501173;0.488725;,
  0.500997;0.499692;,
  0.500953;0.511837;,
  0.500829;0.553752;,
  0.501173;0.863084;,
  0.501071;0.860233;,
  0.500997;0.852119;,
  0.500953;0.839974;,
  0.500939;0.825648;,
  0.999107;0.710392;,
  1.103290;0.710392;,
  0.500893;0.710392;,
  1.103253;0.603195;,
  0.999171;0.603195;,
  0.500829;0.603195;,
  0.555430;0.488725;,
  1.253245;0.488725;,
  0.555430;0.863084;;
 }
}
