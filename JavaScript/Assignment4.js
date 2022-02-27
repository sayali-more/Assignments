const sumProduct = (...allvals) => {
    let sum = allvals.reduce((sum, val) => sum + val);
    let product=1;
    if(sum<0){
        product=-1;
    }
    while (true){
        product=product*(Math.trunc(sum%10));
        sum=Math.trunc(sum/10);
        if(sum==0){
            if(product<10 && product>-10){
                break;
            }
            else{
                sum=product;
                product=1;
            }
        }
    }
    console.log(`For values ${allvals} single digit product is ${product}`);
}
sumProduct(-18,16,-20,6);