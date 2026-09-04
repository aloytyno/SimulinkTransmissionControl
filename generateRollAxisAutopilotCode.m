function artifacts = generateRollAxisAutopilotCode
projectRoot = fileparts(mfilename("fullpath"));
buildRoot = fullfile(projectRoot,"build");
codegenRoot = fullfile(buildRoot,"codegen");
cacheRoot = fullfile(buildRoot,"cache");

assertInstalledProducts(["Simulink Coder","Embedded Coder"]);

if ~isfolder(codegenRoot)
    mkdir(codegenRoot);
end

if ~isfolder(cacheRoot)
    mkdir(cacheRoot);
end

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
slbuild("RollAxisAutopilot");

artifacts = struct( ...
    "BuildFolder",buildRoot, ...
    "CacheFolder",cacheRoot, ...
    "CodeGenFolder",codegenRoot, ...
    "GeneratedModelFolder",fullfile(codegenRoot,"RollAxisAutopilot_ert_rtw"));

clear cleanupConfig
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
