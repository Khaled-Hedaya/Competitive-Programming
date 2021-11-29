
// Style 1 : (Coach Fegla)

double binarySearch(double st , double en){
    for(double sz = (en-st)/2 ; sz>1e-5; sz*=0.5){
        if(isValid(st+sz))
            st+=sz;
    }
    return st;
}


/////////////////////////////////

// Style 2 : (Errichto)

 double binarySearch(double st, double en){
    double L = 0 , R = en, mid;
    while(R - L > eps){ // eps: some very small value (dependent on the problem)
      mid = L + (R - L) / 2;
      if(valid(mid))
        L = mid;
      else
        R = mid;
    }
    return L + (R - L) / 2; // mid
 }
