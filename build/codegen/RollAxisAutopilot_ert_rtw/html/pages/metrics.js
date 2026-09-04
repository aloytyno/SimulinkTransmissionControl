function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "C:\\Users\\aloytyno\\OneDrive - MathWorks\\Documents\\MATLAB\\Examples\\R2026a\\ecoder\\GenerateCCodeFromSimulinkModelsExample\\build\\codegen\\RollAxisAutopilot_ert_rtw\\RollAxisAutopilot.c",
	size: 12};
	 this.metricsArray.var["rtU"] = {file: "C:\\Users\\aloytyno\\OneDrive - MathWorks\\Documents\\MATLAB\\Examples\\R2026a\\ecoder\\GenerateCCodeFromSimulinkModelsExample\\build\\codegen\\RollAxisAutopilot_ert_rtw\\RollAxisAutopilot.c",
	size: 28};
	 this.metricsArray.var["rtY"] = {file: "C:\\Users\\aloytyno\\OneDrive - MathWorks\\Documents\\MATLAB\\Examples\\R2026a\\ecoder\\GenerateCCodeFromSimulinkModelsExample\\build\\codegen\\RollAxisAutopilot_ert_rtw\\RollAxisAutopilot.c",
	size: 4};
	 this.metricsArray.fcn["RollAxisAutopilot_initialize"] = {file: "C:\\Users\\aloytyno\\OneDrive - MathWorks\\Documents\\MATLAB\\Examples\\R2026a\\ecoder\\GenerateCCodeFromSimulinkModelsExample\\build\\codegen\\RollAxisAutopilot_ert_rtw\\RollAxisAutopilot.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["RollAxisAutopilot_step"] = {file: "C:\\Users\\aloytyno\\OneDrive - MathWorks\\Documents\\MATLAB\\Examples\\R2026a\\ecoder\\GenerateCCodeFromSimulinkModelsExample\\build\\codegen\\RollAxisAutopilot_ert_rtw\\RollAxisAutopilot.c",
	stack: 5,
	stackTotal: 5};
	 this.metricsArray.fcn["fabs"] = {file: "C:\\Program Files\\MATLAB\\R2026a_full\\polyspace\\verifier\\cxx\\include\\include-libc\\bits\\mathcalls.h",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="javascript:void(0)" onclick="return postParentWindowMessage({message:\'gotoReportPage\', pageName:\'RollAxisAutopilot_metrics\'});">Global Memory: 44(bytes) Maximum Stack: 5(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
