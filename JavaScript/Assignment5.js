const getDepth = (arr)=>{
    let depth = 1
    for(ele of arr)
    {
        if(Array.isArray(ele)){
            depth++;
        }
    }
    return depth;
     
}

console.log("Depth of given array  is "+getDepth([11, 22, 33, 44]));
console.log("Depth of given array  is "+getDepth([18, [24, 32, 44]]));
console.log("Depth of given array  is "+getDepth([11, [26, [38, 54]]]));
console.log("Depth of given array  is "+getDepth([18, [20, [31, [44]]]]));