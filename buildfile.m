function plan = buildfile
plan = buildplan(localfunctions);

plan.DefaultTasks = "ci";

plan("test").Description = "Run command-line unit tests for the harness model.";
plan("test").Outputs = fullfile("build","test-results","results.xml");

plan("codegen").Description = "Generate C code for RollAxisAutopilot.";
plan("codegen").Outputs = fullfile("build","codegen","RollAxisAutopilot_ert_rtw");

plan("ci").Description = "Run tests and generate code.";
plan("ci").Dependencies = ["test","codegen"];

plan("clean").Description = "Remove local build artifacts.";
end

function testTask(~)
projectRoot = fileparts(mfilename("fullpath"));
resultsFolder = fullfile(projectRoot,"build","test-results");
resultsFile = fullfile(resultsFolder,"results.xml");

if ~isfolder(resultsFolder)
    mkdir(resultsFolder);
end

suite = testsuite(fullfile(projectRoot,"tests"));
runner = matlab.unittest.TestRunner.withTextOutput( ...
    "OutputDetail",matlab.unittest.Verbosity.Detailed);
runner.addPlugin(matlab.unittest.plugins.XMLPlugin.producingJUnitFormat(resultsFile));

results = runner.run(suite);
assertSuccess(results);
end

function codegenTask(~)
generateRollAxisAutopilotCode;
end

function ciTask(~)
end

function cleanTask(~)
projectRoot = fileparts(mfilename("fullpath"));
targets = [ ...
    fullfile(projectRoot,"build")
    fullfile(projectRoot,"slprj")
    fullfile(projectRoot,"RollAxisAutopilot_ert_rtw")];

for target = targets'
    if isfolder(target)
        rmdir(target,"s");
    end
end
end
