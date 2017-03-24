# MC Fake Rate Analysis

## Instructions

1. Merge ntuples from `scripts` directory:  
```
./hadd_script.sh
```

2. Run TTree::MakeClass() from `scripts` directory:  
```
./make_class.sh
```

3. Run from `analysis` directory:  
```
root ../scripts/diphoton_looper.C
```
