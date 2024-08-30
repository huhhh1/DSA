


s = "Hii hii I Am Moksh Sharma motivated third Year Computer science and Enginering student seeking"

tmp = s.split(" ")

tmp.sort((a, b) => {

    for (let i = 0; i < Math.min(a.length, b.length); i++) {

        if (a[i] != b[i]) {
        
            let first_char = a[i].toLowerCase();
            let second_char = b[i].toLowerCase();

            if (first_char == second_char)
                return a[i] < b[i] ? -1 : 0;

            return first_char < second_char ? -1 : 0;
        }
    }
    return a.length < b.length ? -1 : 0;
})

tmp.forEach(i => {
    console.log(i)
})

// ---- OutPut ---- //
/*
    Am
    and
    Computer
    Enginering
    Hii
    hii
    I
    Moksh
    motivated
    Sharma
    science
    seeking
    student
    third   
    Year
*/