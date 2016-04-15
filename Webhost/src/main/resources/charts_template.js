    $(function () {
        $('#[CONTAINER]').highcharts({
            chart: {
                type: 'line'
            },
            title: {
                text: '[TITLE]'
            },
            subtitle: {
                text: '[SUBTITLE]'
            },
            xAxis: {
                type: 'datetime',
                dateTimeLabelFormats: {
                    day: '%e. %b',
                    month: '%b. \'%y',
                    year: '%Y'
                },
                title: {
                    text: 'Date'
                }
            },
            yAxis: {
                title: {
                    text: 'Price ([DEVIZA])'
                },
                min: 0
            },
            tooltip: {
                headerFormat: '<b>{series.name}</b><br>',
                pointFormat: '{point.x:%e. %b}: {point.y:.2f} [DEVIZA]'
            },

            plotOptions: {
                line: {
                    marker: {
                        enabled: true
                    }
                }
            },

            series: [{
                name: '[SERIES1.NAME]',
                data: [
                [SERIES1.DATA]
                ]
            }, {
                name: '[SERIES2.NAME]',
                data: [
                [SERIES2.DATA]
                ]
            }]
        });
    });


