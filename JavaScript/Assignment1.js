let array= [3, 7, 3, 2, 1, 5, 1, 2, 2, -2, 2]
for(let i=0;i<array.length;i++)
{
    if(array[i]==array[i+2]){
        console.log(array.slice(i,i+3));
    }
}
