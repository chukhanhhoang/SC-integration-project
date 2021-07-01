path = '';
file = '';

% fullfilename = fullfile(path, file);
fullfilename = 'D:\Documents\School\TUe\Repositories\5SC26 ball and plate system\Measurements\RefferenceModel\BallAndPlateMeasurement.slx';


[filepath,name,ext] = fileparts(fullfilename);
submodel = '';

submodelName = strrep(submodel,'/','__');
submodelName = '__reduced';
load_system(fullfilename);
print(['-s', name, submodel], ['D:\Documents\MATLAB\ImagesOfSimulinkModels\', name, submodelName], '-dpng', '-r600');
print(['-s', name, submodel], ['D:\Documents\MATLAB\ImagesOfSimulinkModels\', name, submodelName], '-dpdf' ,'-fillpage');
print(['-s', name, submodel], ['D:\Documents\MATLAB\ImagesOfSimulinkModels\', name, submodelName], '-dsvg');
% dos(['pdfcrop ' 'test' '.pdf '  'test' '.pdf &']);