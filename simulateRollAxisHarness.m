function simOut = simulateRollAxisHarness
projectRoot = fileparts(mfilename("fullpath"));
inputData = load(fullfile(projectRoot,"roll_harness_TestInputs.mat"),"Maneuver_1");

simIn = Simulink.SimulationInput("RollAxisAutopilotHarness");
simIn = simIn.setVariable("xin",inputData.Maneuver_1);
simIn = simIn.setModelParameter("ReturnWorkspaceOutputs","on");

simOut = sim(simIn);
end
