function countLoneOnes(number_string){
    let counter=0;
    if(number_string[0]==1 && number_string[1]!=1)
        counter++;
    for(i=1;i<number_string.length;i++){
        if(number_string[i-1]!=1 && number_string[i]==1 && number_string[i+1]!=1){
            counter++;
        }
    }
    return(counter);
}
let numstring="10231152178101101";

console.log("Lone 1's: ",countLoneOnes(numstring));