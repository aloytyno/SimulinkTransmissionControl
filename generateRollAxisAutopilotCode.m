function artifacts = generateRollAxisAutopilotCode
projectRoot = fileparts(mfilename("fullpath"));
buildRoot = fullfile(projectRoot,"build");
codegenRoot = fullfile(buildRoot,"codegen");
cacheRoot = fullfile(buildRoot,"cache");

assertInstalledProducts(["Simulink Coder","Embedded Coder"]);

resetFolder(codegenRoot);
resetFolder(cacheRoot);

originalConfig = Simulink.fileGenControl("getConfig");
cleanupConfig = onCleanup(@() Simulink.fileGenControl( ...
    "set", ...
    "CacheFolder",originalConfig.CacheFolder, ...
    "CodeGenFolder",originalConfig.CodeGenFolder));

Simulink.fileGenControl( ...
    "set", ...
    "CacheFolder",cacheRoot, ...
    "CodeGenFolder",codegenRoot, ...
    "createDir",true);

load_system("RollAxisAutopilot");
cleanupModel = onCleanup(@() localCloseModel("RollAxisAutopilot"));
originalSettings = struct( ...
    "GenCodeOnly",string(get_param("RollAxisAutopilot","GenCodeOnly")), ...
    "GenerateMakefile",string(get_param("RollAxisAutopilot","GenerateMakefile")));
cleanupSettings = onCleanup(@() restoreModelSettings("RollAxisAutopilot",originalSettings));

set_param( ...
    "RollAxisAutopilot", ...
    "GenCodeOnly","on", ...
    "GenerateMakefile","off");
slbuild("RollAxisAutopilot");

artifacts = struct( ...
    "BuildFolder",buildRoot, ...
    "CacheFolder",cacheRoot, ...
    "CodeGenFolder",codegenRoot, ...
    "GeneratedModelFolder",fullfile(codegenRoot,"RollAxisAutopilot_ert_rtw"));

clear cleanupConfig
clear cleanupSettings
clear cleanupModel
end

function assertInstalledProducts(requiredProducts)
installedInfo = ver;
installedProducts = string({installedInfo.Name});
missingProducts = requiredProducts(~ismember(requiredProducts,installedProducts));

if ~isempty(missingProducts)
    error( ...
        "GenerateCCodeFromSimulinkModelsExample:MissingProducts", ...
        "Missing required products for code generation: %s.", ...
        strjoin(missingProducts,", "));
end
end

function localCloseModel(modelName)
if bdIsLoaded(modelName)
    bdclose(modelName);
end
end

function restoreModelSettings(modelName,settings)
if bdIsLoaded(modelName)
    set_param( ...
        modelName, ...
        "GenCodeOnly",settings.GenCodeOnly, ...
        "GenerateMakefile",settings.GenerateMakefile);
end
end

function resetFolder(folderPath)
if isfolder(folderPath)
    rmdir(folderPath,"s");
end

mkdir(folderPath);
end
