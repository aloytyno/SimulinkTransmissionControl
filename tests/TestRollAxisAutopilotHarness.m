classdef TestRollAxisAutopilotHarness < matlab.unittest.TestCase
    properties (Constant, Access = private)
        ProjectRoot = fileparts(fileparts(mfilename("fullpath")))
    end

    methods (TestMethodSetup)
        function addProjectRootToPath(testCase)
            addpath(testCase.ProjectRoot);
            testCase.addTeardown(@() rmpath(testCase.ProjectRoot));
            testCase.addTeardown(@localCloseModel,"RollAxisAutopilot");
            testCase.addTeardown(@localCloseModel,"RollAxisAutopilotHarness");
        end
    end

    methods (Test)
        function harnessSimulationLogsExpectedSignals(testCase)
            simOut = simulateRollAxisHarness;
            logs = simOut.logsout;

            testCase.verifyEqual(logs.numElements,2);

            aileronCommand = logs.get("Ail_Cmd").Values;
            rollAttitude = logs.get("Roll Attitude").Values;

            testCase.verifyEqual([aileronCommand.Time(1) aileronCommand.Time(end)],[0 30],AbsTol=eps);
            testCase.verifyEqual(numel(aileronCommand.Data),1201);
            testCase.verifyTrue(all(isfinite(aileronCommand.Data(:))));
            testCase.verifyLessThan(max(abs(aileronCommand.Data(:))),30);

            testCase.verifyEqual([rollAttitude.Time(1) rollAttitude.Time(end)],[0 30],AbsTol=eps);
            testCase.verifyEqual(numel(rollAttitude.Data),1201);
            testCase.verifyTrue(all(isfinite(rollAttitude.Data(:))));
            testCase.verifyLessThan(max(abs(rollAttitude.Data(:))),30);
        end

        function autopilotModelUsesEmbeddedCoderTarget(testCase)
            load_system("RollAxisAutopilot");

            testCase.verifyEqual( ...
                string(get_param("RollAxisAutopilot","SystemTargetFile")), ...
                "ert.tlc");
        end
    end
end

function localCloseModel(modelName)
if bdIsLoaded(modelName)
    bdclose(modelName);
end
end
