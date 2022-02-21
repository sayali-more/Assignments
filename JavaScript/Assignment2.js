function number_string(array_string){
    let return_array=[];
    while(string=array_string.pop()){
        if(string.match(/\d/)){
            return_array.push(string);
        }
   }
   return(return_array);
}

let array_string=["abc","abc123","1xyz","123","lnm","pqr"];
console.log(number_string(array_string));

