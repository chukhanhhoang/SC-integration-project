load('u_1.mat');
LUTObj = Simulink.LookupTable;
LUTObj.Table.Value = u;
t=0:0.001:20;
t=t(1:end-1);
t=t';
LUTObj.Breakpoints(1).Value = t;
LUTObj.StructTypeInfo.Name = 'myLUTStruct';

LUTObj.CoderInfo.StorageClass = 'Custom';
LUTObj.CoderInfo.CustomStorageClass = 'Struct';
LUTObj.CoderInfo.CustomAttributes.StructName = 'xdir';

%rtwbuild('Lookuptable')