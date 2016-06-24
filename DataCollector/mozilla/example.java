      File grePath = new File("src/lib/xulrunner");
        
        JWeb.start(grePath.getAbsolutePath());
        jweb = new JWeb();
        
        JFrame frame = new JFrame();
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        panel.add(jweb, BorderLayout.CENTER);
        frame.getContentPane().add(panel);

                frame.setVisible(true);

        nsIWebProgress webProgress = (nsIWebProgress) 
jweb.getInterface(nsIWebProgress.NS_IWEBPROGRESS_IID);
        nsIWebNavigation webNavigation = (nsIWebNavigation) 
jweb.getInterface(nsIWebNavigation.NS_IWEBNAVIGATION_IID);

        WebProgressListener aWebProgressListener = new WebProgressListener();
        webProgress.addProgressListener(aWebProgressListener,
                                 nsIWebProgress.NOTIFY_ALL);
        webNavigation.loadURI("http://www.debian.org",0,null,null,null);