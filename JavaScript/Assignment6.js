const inp1=(a,b)=>{
    console.log("\nOutput of Arrow function: "+(a+b));
};
const inp2=function(a,b){
    console.log("\nOutput of Normal function: "+(a-b));
}

const checkFunction=(inpString)=>{
    if(inpString[0]=="("){
        eval(inpString);
        inp1(2,3);
        console.log("Conversion of arrow funtion to normal functiom: ");
        let outString="function normalFunction"+inpString.slice(inpString.indexOf("("),inpString.indexOf(")")+1);
        outString=outString+inpString.slice(inpString.indexOf("{"),inpString.indexOf("}")+1);
        console.log(outString+"\n");
    }
    else{
        let outString=inpString.slice(inpString.indexOf("("),inpString.indexOf(")")+1)+"=>";
        outString=outString+inpString.slice(inpString.indexOf("{"),inpString.indexOf("}")+1)+";";
        eval(outString);
        inp2(10,3);
        console.log("Conversion of normal funtion to arrow functiom: ");
        console.log(outString+"\n");
    }
}

checkFunction(""+inp1);
checkFunction(""+inp2);