test()
    {
        echo "no quotation, they are same"
        echo $*
        echo $@
        echo "add quotation, they are different"
        for _ in "$*"	
        do
            echo $_
        done
        for _ in "$@"
        do
            echo $_
        done

    }

    test 12 123 3424 546
