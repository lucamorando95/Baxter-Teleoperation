function [y1] = myNeuralNetworkFunction(x1)
%MYNEURALNETWORKFUNCTION neural network simulation function.
%
% Generated by Neural Network Toolbox function genFunction, 26-Feb-2018 09:50:11.
% 
% [y1] = myNeuralNetworkFunction(x1) takes these arguments:
%   x = 12xQ matrix, input #1
% and returns:
%   y = 7xQ matrix, output #1
% where Q is the number of samples.

%#ok<*RPMT0>

% ===== NEURAL NETWORK CONSTANTS =====

% Input 1
x1_step1.xoffset = [-0.66825;-1.04459;-1.425375;-0.67369;-1.04678;-0.38591;-0.722014;-1.04376;-0.598492;-1.425375;-0.963446;-1.166];
x1_step1.gain = [1.52022006705691;1.34982823435718;0.474752879257525;1.56752587985228;1.17576858522706;0.985192555885048;1.45094079000824;1.17747143895841;0.837597402107898;0.474752879257525;1.20462624663759;0.657263418032679];
x1_step1.ymin = -1;

% Layer 1
b1 = [-3.4117870555197136184;-52.666900492200340977;1.7795118358358363864;21.581676344942728463;3.2149261534792827888;-9.7951180881838109116;32.838963239695956986;-3.4272165166254220381;4.5946077260217546012;-14.620702141009628505];
IW1_1 = [0.23345084891950412809 2.3915790037165582937 8.3538030839397467986 1.0268312907529972833 -1.234976439597998521 -0.39268038124258086707 3.4881988436085125116 1.1244025507328914149 -2.2345426542588615604 -6.8157299541511413565 0.57800123716055629153 2.0284386997957137844;-10.160538931356434489 25.043636916715257712 49.520905258334565247 -3.4323620704054498276 -22.890426414249368747 -29.466317761186274993 19.823505690980081084 2.0430856403967592172 -34.79034813698782358 -37.180757583867176663 32.389650615652811894 -23.01157009055899394;-0.083141748010230429045 0.47243729781328336337 -6.2898933671389007927 -1.1617382285803570241 1.5085757770895327212 1.7347353175783799539 -4.8214353062131172223 -1.3179502458758753924 -0.83445094504347783193 4.2042928782157762413 0.06150418612599092838 -1.4531733564339461839;-9.8603000052067368841 2.3484026500957524419 -57.759760187001646159 -26.793133615457989549 -9.2411461163723238599 44.179088697347417281 30.799022389883788264 13.986320475910250849 -19.181889537674955193 52.953208684402426343 -1.7394274155771534129 3.8786031631582655876;-12.105703684487576055 -0.81865253434118212539 23.602751077349399367 -5.9442867640149890107 1.4968699081154326347 5.3859588503610948962 -1.2150529146261852542 -3.2359684210338097721 -6.3121529902989124139 -20.525595209164233523 -7.4739702099903446708 8.2196600621562652123;-18.267627503293564217 4.4652258365237287308 -31.551947419771405379 38.300879145774210599 -0.31924543939587463059 78.28225298435934576 -28.373617140665132297 12.398004694678641968 -100.33652686035574675 -20.490666657443671994 5.3353663677738953908 3.3045801417733451366;9.8001212920214211266 -6.2628519046829929096 -18.431882794526405434 5.3042367377688357521 23.019143718840016533 25.72673440478439133 -23.40118306002873183 -1.916228182174523953 1.2856657180390382855 13.051293934026530152 -28.499173986073113696 45.287726914391569721;11.856483984428374256 0.96238537456642880841 -23.793219477040381094 5.8997359464906908855 -1.5019968048787402104 -5.5116041744545576364 1.2860648084810795133 3.4751146659842921949 6.1148152802236612757 20.460403946620520088 7.2037367450978528893 -7.6251146943563528069;-14.467493693561657153 3.1430626780841621759 22.223522610692274526 2.6710027694711513391 -4.6472944161657334661 24.923486642550237491 -6.0237828225041294417 26.856380211308483297 -4.9837895757955603671 -9.9399715108055666235 -11.592219667300012631 -3.3245029499885134783;-0.60408399224744746547 0.43250328399974652394 37.405386821785661766 4.2734529460949213231 0.38309881958698766002 -29.784961898292237947 -0.21683563228608754292 0.78000106250684109188 19.465683872375606711 -31.053839611965877054 1.6491474193273303328 -3.2900416210668197436];

% Layer 2
b2 = [-0.36765976423098090109;-0.65056917244554490765;-0.064635308868470867094;0.32819409054783960089;-0.39954712761005284349;-0.076930886406147605538;-0.61686931055854177242];
LW2_1 = [-0.055895757805407064733 -0.46535359884208066239 0.26156736484370285423 -0.14181886566201792887 -0.3245195717924451162 -0.31779869809091310096 -0.49967592729304088905 -0.34069195865775214749 -0.022580649348857968067 -0.38599501555720105994;-0.66924061523100641935 0.076691789233890306221 -0.63951477772108100694 -0.056937076017683579954 9.4578697987958104676 0.028927786022141455807 0.051817080506695832598 9.4691861550299005756 0.18088718089952288137 -0.24810979940210431405;-0.072943914130961462483 0.11281516168864992589 -0.66388226133998062828 0.00043322382215998673366 3.9195962010462985781 0.094314248511614212633 0.10277894904498546813 3.9106724838042663528 0.14716755162482669794 -0.1076779708983125472;-0.71645460619191936313 -0.085305444323372642268 -0.49601829366948779754 -0.085164620341275823479 -1.8742928278351700389 0.11606473261081139137 -0.081133141725454951954 -1.8633110255800782173 -0.10892814954084935331 0.074304978356505180237;-0.15130895854187353944 -1.1871882911198250454 -0.15500240533538997556 -0.60590037885666836459 0.32321709844452445326 -0.56670977940276223705 -1.1596338684231548566 0.33341006472953427231 -0.10488894529770385888 -1.0881644615378562868;0.03381001594596534654 -0.18074008473362082605 0.063096488779316006745 -0.044228609971490723263 -3.8899870673107539432 -0.12739819147066122618 -0.1805657041368428084 -3.894851369413156128 -0.11578216463836739358 -0.061257182121493100602;-0.20368733980503353487 -1.0130649978249717247 -0.19381620683917741288 -0.54439289610708685441 -2.8330218501566992728 -0.51099363175730272424 -1.0311290193008755267 -2.8311886106862207413 0.074976103516014622197 -1.137680551785944516];

% Output 1
y1_step1.ymin = -1;
y1_step1.gain = [3.22919189472834;0.924513090157731;1.08944804204398;1.86991383437051;0.534343598964442;0.912863108417556;0.713724166307723];
y1_step1.xoffset = [-1.69812;-0.0494709;-0.83602;-0.841005;-2.72243;-1.27704;-1.98229];

% ===== SIMULATION ========

% Dimensions
Q = size(x1,2); % samples

% Input 1
xp1 = mapminmax_apply(x1,x1_step1);

% Layer 1
a1 = tansig_apply(repmat(b1,1,Q) + IW1_1*xp1);

% Layer 2
a2 = repmat(b2,1,Q) + LW2_1*a1;

% Output 1
y1 = mapminmax_reverse(a2,y1_step1);
end

% ===== MODULE FUNCTIONS ========

% Map Minimum and Maximum Input Processing Function
function y = mapminmax_apply(x,settings)
  y = bsxfun(@minus,x,settings.xoffset);
  y = bsxfun(@times,y,settings.gain);
  y = bsxfun(@plus,y,settings.ymin);
end

% Sigmoid Symmetric Transfer Function
function a = tansig_apply(n,~)
  a = 2 ./ (1 + exp(-2*n)) - 1;
end

% Map Minimum and Maximum Output Reverse-Processing Function
function x = mapminmax_reverse(y,settings)
  x = bsxfun(@minus,y,settings.ymin);
  x = bsxfun(@rdivide,x,settings.gain);
  x = bsxfun(@plus,x,settings.xoffset);
end
