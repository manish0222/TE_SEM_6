let ans="";
let buttons=document.getElementsByClassName("button");
let op=document.querySelector(".output");
Array.from(buttons).forEach((button)=>{
    button.addEventListener('click',(e)=>{
        if(e.target.innerHTML==='='){
            try{
                ans=eval(ans);
                // console.log(ans);
                if(ans!==Infinity)op.value=ans;
                else alert("Error");
                // ans="";
            }
            catch(e){
                ans="";
                op.value=ans;
                alert("Error",e);
            }
        }
        else if(e.target.innerHTML==='C'){
            ans="";
            op.value=ans;
        }
        else{
            ans=ans + e.target.innerHTML;
            console.log(ans);
            op.value=ans;
        }
    })
})