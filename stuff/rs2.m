yale_0 = [0.823  0.823  0.897  0.920  0.880  0.897  0.770  0.903  0.953  0.887  0.913  0.827  0.893 0.813 0.887 0.913 0.847];
yale_1 = [0.857  0.803  0.900  0.930  0.890  0.900  0.807  0.913  0.950  0.880  0.863  0.807  0.860 0.807 0.853 0.903 0.820];
yale_2 = [0.827  0.797  0.820  0.820  0.830  0.837  0.783  0.910  0.923  0.830  0.870  0.797  0.883 0.833 0.870 0.913 0.790];
yale_3 = [0.933  0.837  0.873  0.927  0.853  0.880  0.793  0.910  0.927  0.847  0.927  0.853  0.937 0.807 0.860 0.883 0.867]; 

att_0 = [0.946  0.973  0.985  0.950  0.953  0.980  0.797  0.882  0.907  0.990  0.925  0.971  0.979 0.985 0.956 0.966 0.973];
att_1 = [0.933  0.960  0.983  0.951  0.954  0.980  0.792  0.863  0.905  0.989  0.916  0.950  0.963 0.985 0.849 0.964 0.959];
att_2 = [0.719  0.720  0.978  0.941  0.919  0.980  0.643  0.929  0.711  0.975  0.760  0.660  0.711 0.974 0.828 0.960 0.719];
att_3 = [0.906  0.875  0.970  0.924  0.935  0.955  0.667  0.895  0.864  0.963  0.850  0.859  0.912 0.969 0.850 0.935 0.873];

lfw_0 = [0.686  0.461  0.755  0.594  0.705  0.636  0.357  0.397  0.656  0.634  0.494  0.451  0.720 0.843 0.512 0.777 0.461];
lfw_1 = [0.715  0.564  0.765  0.600  0.695  0.612  0.349  0.491  0.664  0.720  0.566  0.576  0.724 0.841 0.379 0.781 0.564];
lfw_2 = [0.514  0.449  0.694  0.582  0.568  0.564  0.293  0.480  0.548  0.638  0.368  0.397  0.516 0.773 0.462 0.769 0.447];
lfw_3 = [0.707  0.687  0.749  0.580  0.697  0.657  0.271  0.506  0.652  0.773  0.588  0.672  0.719 0.825 0.554 0.747 0.687];


labels = { "fisher" "eigen" "lbph" "lbph_u" "minmax" "lbp_com" "lbp_var" "ltph" "clbpdis" "wld" "mom" "zernike" "svm" "svm_lbp" "svm_hu" "svm_hog" "norml2"};
idx = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17];

figure;
plot(lfw_0,idx,lfw_1,idx,lfw_2,idx,lfw_3,idx);
title("lfw");
for i = [1:17] text(1,i, char(labels(i))); end
legend("none", "equ_hist", "tan_triggs", "clahe",'Location','SouthEast');
grid minor

figure;
plot(att_0,idx,att_1,idx,att_2,idx,att_3,idx);
title("att");
for i = [1:17] text(1,i, char(labels(i))); end
legend("none", "equ_hist", "tan_triggs", "clahe",'Location','SouthWest');
grid minor

figure;
plot(yale_0,idx,yale_1,idx,yale_2,idx,yale_3,idx);
title("yale");
for i = [1:17] text(1,i, char(labels(i))); end
legend("none", "equ_hist", "tan_triggs", "clahe",'Location','SouthEast');
grid minor


